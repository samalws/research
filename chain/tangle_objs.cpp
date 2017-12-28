#include <vector>
#include <array>
#include "byteable.cpp"
#include "crypto.cpp"
#include "eth_style_txn.cpp"
#include "punishment_reward_txn.cpp"

#ifndef TANGLE_OBJS_CPP
#define TANGLE_OBJS_CPP

namespace chain {
  template <class baseTxn>
  struct Tangle_Block_Noncefree: Byteable {
    typedef const std::array<Mined_Obj const*, 2> twoTangles;

    const baseTxn transaction;
    const twoTangles tanglesApproved;

    std::vector<char> getBytes() const {
      std::vector<char> txnHash = transaction.getBytes();
      for (int i=0;i<2;i++) {
        std::array<char, 512> h = hash(tanglesApproved[i]->getBytes());
        txnHash.insert(txnHash.end(), h.data(), h.data()+h.size());
      }
      return std::vector<char>();
    }

    Tangle_Block_Noncefree(const baseTxn t, twoTangles a):
      transaction(t), tanglesApproved(a) {}
    Tangle_Block_Noncefree(const baseTxn t): Tangle_Block_Noncefree(t, twoTangles()) {}
    Tangle_Block_Noncefree(): Tangle_Block_Noncefree(baseTxn()) {}
  };
}

#endif
#include "byteable.cpp"
#include "code.cpp"

#ifndef PUNISHMENT_REWARD_TXN_CPP
#define PUNISHMENT_REWARD_TXN_CPP

namespace chain {
  struct PunRwrdSolutionTxn: public Byteable {
    CodeResults results;
    bool firstSolution;
    void *previousEntry; //can point to PunRwrdSolutionTxn or CodeTxn
    Pubkey solver;
    Signature signature;
    std::vector<char> getBytes() const; //TODO
  };
  struct PunRwrdCapTxnNoncefree: public Byteable {
    Pubkey solver;
    PunRwrdSolutionTxn *affirmed;
    PunRwrdSolutionTxn *overridden;
    Signature signature;
    std::vector<char> getBytes() const; //TODO
  };
  enum class PunishmentRewardTxnType { CodeTxn, SolutionTxn, CapTxn };
  struct PunishmentRewardTxn: public Byteable {
    union {
      struct CodeTxn codeTxn; //why this needs "struct" but everything else doesn't is beyond me
      PunRwrdSolutionTxn solutionTxn;
      MinedObj capTxn;
    } txn;
    PunishmentRewardTxnType type;
    std::vector<char> getBytes() const; //TODO
  };
}

#endif

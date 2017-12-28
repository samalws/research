#include <vector>
#include "byteable.cpp"
#include "crypto.cpp"

#ifndef CODE_CPP
#define CODE_CPP

namespace chain {
  typedef unsigned long MoneyAmt;
  typedef unsigned long GasAmt;
  struct Code {};
  struct CodeTxn: public Byteable {
    Code code;
    Pubkey signer;
    Signature signature;
    MoneyAmt gasPrice;
    GasAmt maxGas;
    std::vector<char> getBytes() const; //TODO
  };
  struct CodeResult: public Byteable {
    Pubkey recipient;
    MoneyAmt amount;
    std::vector<char> getBytes() const; //TODO
  };
  struct CodeResults: public Byteable {
    std::vector<CodeResult> moneyTransferred;
    GasAmt gasUsed; //0: maxGas was too low
    std::vector<char> getBytes() const; //TODO
  };
}

#endif
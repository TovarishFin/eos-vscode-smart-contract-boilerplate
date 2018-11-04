#include <eosiolib/eosio.hpp>
#include <eosiolib/print.hpp>

using namespace eosio;

class hello : public contract {
  public:
    using contract::contract;

    [[eosio::action]]
    void hi(name user) {
      print("Hello ", name{user});
    }

    [[eosio::action]]
    void bye(name user) {
      print("Bye ", name{user});
    }
};

EOSIO_DISPATCH(hello, (hi)(bye))
# EOS VSCode Starter Kit
This is a set of boilerplate in order to develop smart contracts using VSCode. It includes the needed `c_cpp_properties.json` file in `.vscode` for recognizing `#include`s from `eosiolib`.

## Prior knowledge required
You should have at least completed the ["start here" section on dev docs](https://developers.eos.io/eosio-home/docs) 

## Important notes
**This setup is intended for users running mac OSX...** but I would imagine the same would work for most popular versions of linux by just replacing `brew` with whatever use use... perhaps `apt`?

This will not work on its own! Before attempting to use this you must do the following:
1. install nodeos, keosd, & cleos via docker
  * [see eosio docs for installation using docker](https://developers.eos.io/eosio-home/docs/getting-the-software)
1. install EOS contract development toolkit
  * `brew tap eosio/eosio.cdt`
  * `brew install eosio.cdt`
1. create needed symlinks
  * navigate to `/usr/local/include/`
  * `ln -s /usr/local/Cellar/eosio.cdt/1.3.2/opt/eosio.cdt/include/eosiolib`
  * navigate to `/usr/local/include/eosiolib`
  * `lin -s /usr/local/Cellar/eosio.cdt/1.3.2/opt/eosio.cdt/include/boost`

After completing the above steps your VSCode should recognize `#include`s and intellisense should work.

## Compiling/Deploying Contracts
Comple the contract:

```eosio-cpp -o hello.wasm  hello.cpp --abigen```

Open wallet:

```cleos wallet open```

Unlock wallet:

```cleos wallet unlock```

Create an account for the contract:

```cleos account create hello $EOS_PUBLIC_KEY```

Create the contract:

```cleos set contract hello $EOS_CONTRACT_DIR/hello```

Update the contract:
1. make changes
2. compile
3. Same as create
4. done

## Interacting with the contract
Create another account if you dont have one:

```cleos account create bob $EOS_PUBLIC_KEY```

Call hi on hello:

```cleos push action hello hi '["bob"]' -p bob```

You should get the following back:

```>> Hello bob```

Call bye on hello:

```cleos push action hello bye '["bob"]' -p bob```

You should get the following back:

```>> Bye bob```

## Creating your own contract
clone/fork/do whatever ytou want with this. The important files are in `.vscode`.
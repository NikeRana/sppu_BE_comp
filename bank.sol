// SPDX-License-Identifier: MIT
pragma solidity 0.8;

contract Bank{
    int bal;
    
    constructor() {
        bal = 1;
    }

    function getBalance() view public returns(int) {
        return bal;
    }

    function withdraw(int amt) public {
        bal = bal - amt;
    }

    function deposit(int amt) public{
        bal = bal + amt;
    }

}
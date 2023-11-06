// SPDX-License-Identifier: MIT
pragma solidity ^0.8.0;

contract StudentData {
    struct Student {
        string name;
        uint256 rollNumber;
        uint256 age;
    }

    Student[] public students;

    event StudentAdded(string name, uint256 rollNumber, uint256 age);

    // Add a new student record
    function addStudent(string memory name, uint256 rollNumber, uint256 age) public {
        Student memory newStudent = Student(name, rollNumber, age);
        students.push(newStudent);
        emit StudentAdded(name, rollNumber, age);
    }

    // Retrieve the number of students
    function getNumberOfStudents() public view returns (uint256) {
        return students.length;
    }

    // Retrieve student information by index
    function getStudent(uint256 index) public view returns (string memory, uint256, uint256) {
        require(index < students.length, "Student does not exist");
        Student memory student = students[index];
        return (student.name, student.rollNumber, student.age);
    }

    // Fallback function (if Ether is sent to this contract, it reverts the transaction)
    receive() external payable {
        revert("This contract does not accept Ether.");
    }
}

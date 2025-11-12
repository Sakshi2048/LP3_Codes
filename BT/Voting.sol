// SPDX-License-Identifier: MIT
pragma solidity ^0.8.20;

contract Voting {
    
    struct Candidate {
        uint256 id;
        string name;
        string party;
        uint256 voteCount;
    }

    mapping(uint256 => Candidate) public candidates;
    mapping(address => bool) public voters;
    
    uint256 public candidateCount;
    uint256 public votingEnd;
    uint256 public votingStart;

    function addCandidate(string memory name, string memory party) public returns (uint256) {
        candidateCount++;
        candidates[candidateCount] = Candidate(candidateCount, name, party, 0);
        return candidateCount;
    }

    function vote(uint256 candidateID) public {
        require(votingStart <= block.timestamp && votingEnd > block.timestamp, "Voting not active");
        require(candidateID > 0 && candidateID <= candidateCount, "Invalid candidate");
        require(!voters[msg.sender], "Already voted");
        voters[msg.sender] = true;
        candidates[candidateID].voteCount++;
    }

    function checkVote() public view returns (bool) {
        return voters[msg.sender];
    }

    function getCountCandidates() public view returns (uint256) {
        return candidateCount;
    }

    function getCandidate(uint256 candidateID) public view returns (uint256, string memory, string memory, uint256) {
        Candidate storage c = candidates[candidateID];
        return (candidateID, c.name, c.party, c.voteCount);
    }

    function setDates(uint256 _startDate, uint256 _endDate) public {
        require(votingEnd == 0 && votingStart == 0, "Dates already set");
        require(_startDate + 1000000 > block.timestamp, "Start date too early");
        require(_endDate > _startDate, "End must be after start");
        votingEnd = _endDate;
        votingStart = _startDate;
    }

    function getDates() public view returns (uint256, uint256) {
        return (votingStart, votingEnd);
    }
}

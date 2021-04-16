# SDLC Activity Based Learning

Visit [Pages for Report -optional](using github.io option)

Build | Code Quality | Unity | [Git Inspector](using github.io option)
------|----------|-------|--------------
[C/C++ CI]| [![Static Code - Cppcheck](https://github.com/codemonk-007/LnT_Mini-Project1/actions/workflows/cpp-check.yml/badge.svg)](https://github.com/codemonk-007/LnT_Mini-Project1/actions/workflows/cpp-check.yml) 2.[Dynamic Valgrind]TBD| [Unity - Unit Testing] TBD| [![Git Inspector](https://github.com/codemonk-007/LnT_Mini-Project1/actions/workflows/gir_inspect.yml/badge.svg)](https://github.com/codemonk-007/LnT_Mini-Project1/actions/workflows/gir_inspect.yml)|


## Folder Structure
Folder             | Description
-------------------| -----------------------------------------
`1_Requirements`   | Documents detailing requirements and research
`2_Design`         | Documents specifying design details
`3_Implementation` | All code and documentation
`4_Test_plan`      | Documents with test plans and procedures

## Contributors List and Summary

SFID  |  Name   |    Features    | Issuess Raised |Issues Resolved|No Test Cases|Test Case Pass
-------|---------|----------------|----------------|---------------|-------------|--------------
258695 | Jay Singh  | F1,F2,F3,F4,F5,F6,F7    | 5    | 4 |0  |0   
   

| Feature Id | Feature |
| -----------|---------|
|F1| Option to View All udhaar Data |
|F2| Option to Add new transaction to Udhaar data|
|F3| Option to Update old Udhaar Record |
|F4| If while entering new data, record already exist, redirects to updating record option|
|F5| If while updating old data, record does not exist,redirects to new record updating option|
|F6| On updation, the time stamp is automatically updated using the UTC time from System.|
|F7| All credits are dispalyed in Green and All  debts displayed in Red.

## Challenges Faced and How Was It Overcome

1. Subsantial Segment Faults while reading file data.(Still fixing)
2. File write format was being destroyed in each update peration.Fixed it by using fsacnf while helps to read formatted data.
3. User name could not be read from file if space existed. Broke name into first name and last name data fields.
4. Updated Time stamp's structure to multiple fields in order to read from file effortlessly as strings with space destroyed formatted reading from file.
5. File data was not being searched properly. Existing records were displayed as non existant. Was a file pointer issue. Used fseek() to position file pointer to top of file after on complete read operation on file.




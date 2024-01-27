-- Creating table : DEPARTMENT
CREATE TABLE DEPARTMENT (
    ID INT PRIMARY KEY,
    Name VARCHAR(255) NOT NULL,
    Location VARCHAR(255)
);



-- Creating table : EMPLOYEE
CREATE TABLE EMPLOYEE (
    ID INT PRIMARY KEY,
    Name VARCHAR(255) NOT NULL,
    DepartmentID INT,
    ManagerID INT,
    Salary DECIMAL(10, 2),
    FOREIGN KEY (DepartmentID) REFERENCES DEPARTMENT(ID),
    FOREIGN KEY (ManagerID) REFERENCES EMPLOYEE(ID)
);


-- Adding indexs
CREATE INDEX idx_department_id ON EMPLOYEE(DepartmentID);

-- Adding indexs
CREATE INDEX idx_manager_id ON EMPLOYEE(ManagerID);

-- Inserting data to table : DEPARTMENT
INSERT INTO DEPARTMENT (ID, Name, Location) VALUES
(1, 'Engineering', 'Bangalore'),
(2, 'Sales', 'Delhi'),
(3, 'Operations', 'Delhi'),
(4, 'Product', 'Bangalore'),
(5, 'Production', 'Hyderabad');


-- Inserting data to table : EMPLOYEE
INSERT INTO EMPLOYEE (ID, Name, DepartmentID, ManagerID, Salary) VALUES
(1, 'Ram', 1, NULL, 200000),
(2, 'Vimal', 1, 1, 150000),
(3, 'Albert', 1, 1, 100000),
(4, 'John', 2, NULL, 200000),
(5, 'Taj', 2, 4, 100000),
(6, 'Deepak', 2, 4, 75000),
(7, 'Raju', 3, NULL, 100000),
(8, 'Ramesh', 3, 7, 50000),
(9, 'Jyoti', 4, NULL, 200000),
(10, 'Prince', 5, NULL, 200000);



--  List Department Wise Employee Count at Each Location:
SELECT D.Name AS Department, D.Location, COUNT(E.ID) AS EmployeeCount FROM DEPARTMENT D
LEFT JOIN EMPLOYEE E ON D.ID = E.DepartmentID 
GROUP BY D.Name, D.Location;

--list the avg salary of employees under each manager
SELECT Manager.Name AS Manager, AVG(E.Salary) AS AverageSalary FROM EMPLOYEE as E
JOIN EMPLOYEE as Manager ON E.ManagerID = Manager.ID
GROUP BY Manager.Name;

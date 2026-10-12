DECLARE
    eno emp.empno%type;
    name emp.ename%type;
    sal emp.salary%type;

    employee_not_found EXCEPTION;
    salary_above_limit EXCEPTION;

BEGIN
    eno := &employee_number;

    BEGIN
        SELECT ename, salary
        INTO name,sal
        FROM emp
        WHERE empno = eno;

    EXCEPTION
        when NO_DATA_FOUND then
            RAISE employee_not_found;
    END;


    DBMS_OUTPUT.PUT_LINE('Employee number :' ||eno);
    DBMS_OUTPUT.PUT_LINE('Employee name : ' ||name);
    DBMS_OUTPUT.PUT_LINE('Salary: ' || sal);


    IF sal > 25000 then

        RAISE salary_above_limit;

    ELSIF sal < 25000 then

        UPDATE emp
        SET salary = 25000
        WHERE empno = eno;

        DBMS_OUTPUT.PUT_LINE('Salary was less than 25000. Salary updated to 25000.');

    ELSE

        DBMS_OUTPUT.PUT_LINE('Salary is already 25000.');

    END IF;


EXCEPTION
    WHEN employee_not_found then
        DBMS_OUTPUT.PUT_LINE('ERROR: Employee number ' ||eno|| ' does not exist.');

    WHEN salary_above_limit then
        DBMS_OUTPUT.PUT_LINE('ERROR: Employee salary is more than 25000.');

    WHEN OTHERS then
        DBMS_OUTPUT.PUT_LINE('ERROR: ' || SQLERRM);
END;
/

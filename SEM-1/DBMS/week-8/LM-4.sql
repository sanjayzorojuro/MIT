create or replace TRIGGER tsal
AFTER UPDATE OF salary ON emp
FOR EACH ROW
DECLARE
    dname dept.dname%TYPE;
BEGIN

    SELECT dname
    INTO dname
    FROM dept
    WHERE dno = :OLD.deptno;

    INSERT INTO SAL_MOD
    (
        Empno,
        Dname,
        Old_Sal,
        Mod_Date,
        Modifier
    )
    VALUES
    (
        :OLD.empno,
        dname,
        :OLD.salary,
        SYSDATE,
        USER
    );

END;
/


CREATE OR REPLACE PROCEDURE dept_total_sal IS
    CURSOR c_dept_sal IS
        SELECT d.DNAME, NVL(SUM(e.SAL), 0) as TOTAL_SAL
        FROM DEPT d
        LEFT JOIN EMP e ON d.DNO = e.DEPTNO
        GROUP BY d.DNAME;
BEGIN
    DBMS_OUTPUT.PUT_LINE('DEPARTMENT | TOTAL SALARY');
    DBMS_OUTPUT.PUT_LINE('-------------------------');
    
    FOR rec IN c_dept_sal LOOP
        DBMS_OUTPUT.PUT_LINE(rec.DNAME || ' | ' || rec.TOTAL_SAL);
    END LOOP;
END;
/

EXEC dept_total_sal;
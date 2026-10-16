CREATE OR REPLACE FUNCTION get_dept_totalfund(p_dno IN DEPT.DNO%TYPE) 
RETURN NUMBER IS
    v_total NUMBER;
BEGIN
    SELECT NVL(SUM(PRJ_FUND), 0) INTO v_total
    FROM PROJ
    WHERE DNO = p_dno;
    
    RETURN v_total;
END;
/

DECLARE
    CURSOR c_dept IS SELECT DNO, DNAME FROM DEPT;
    v_fund NUMBER;
BEGIN
    FOR rec IN c_dept LOOP
        v_fund := get_dept_totalfund(rec.DNO);
        DBMS_OUTPUT.PUT_LINE(rec.DNAME || ' department has received Rs. ' || v_fund || '/-');
    END LOOP;
END;
/
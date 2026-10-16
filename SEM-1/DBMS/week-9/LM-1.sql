CREATE OR REPLACE PROCEDURE emp_exp IS
    CURSOR c_emp IS
        SELECT EMPNO, ENAME, DATE_BIRTH, DATE_JOIN FROM EMP;
    
    v_age          NUMBER;
    v_experience   NUMBER;
BEGIN
    DBMS_OUTPUT.PUT_LINE('EMPNO | ENAME | AGE (Years) | EXPERIENCE (Years)');
    DBMS_OUTPUT.PUT_LINE('---------------------------------------------------');
    
    FOR rec IN c_emp LOOP
        v_age := FLOOR(MONTHS_BETWEEN(SYSDATE, rec.DATE_BIRTH) / 12);
        v_experience := FLOOR(MONTHS_BETWEEN(SYSDATE, rec.DATE_JOIN) / 12);
        
        DBMS_OUTPUT.PUT_LINE(rec.EMPNO || ' | ' || rec.ENAME || ' | ' || v_age || ' | ' || v_experience);
    END LOOP;
END;
/

EXEC emp_exp;
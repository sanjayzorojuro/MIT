CREATE OR REPLACE PROCEDURE dept_projects(p_dname IN DEPT.DNAME%TYPE) IS
    CURSOR c_proj IS
        SELECT p.PRJ_NO, p.PRJ_NAME, e.ENAME
        FROM PROJ p
        JOIN EMP e ON p.DNO = e.DEPTNO
        JOIN DEPT d ON p.DNO = d.DNO
        WHERE d.DNAME = p_dname;
        
    v_found BOOLEAN := FALSE;
BEGIN
    DBMS_OUTPUT.PUT_LINE('Projects and Employees for Department: ' || p_dname);
    DBMS_OUTPUT.PUT_LINE('-------------------------------------------');
    
    FOR rec IN c_proj LOOP
        v_found := TRUE;
        DBMS_OUTPUT.PUT_LINE('Project: ' || rec.PRJ_NAME || ' (ID: ' || rec.PRJ_NO || ') - Employee: ' || rec.ENAME);
    END LOOP;
    
    IF NOT v_found THEN
        DBMS_OUTPUT.PUT_LINE('No projects found for this department.');
    END IF;
EXCEPTION
    WHEN NO_DATA_FOUND THEN
        DBMS_OUTPUT.PUT_LINE('Department not found.');
END;
/

EXEC dept_projects('IT');
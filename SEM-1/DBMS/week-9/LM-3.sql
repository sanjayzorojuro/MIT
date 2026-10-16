CREATE OR REPLACE FUNCTION fn_get_project_status(p_prj_no IN PROJ.PRJ_NO%TYPE)
RETURN VARCHAR2 IS
    v_total_tasks NUMBER;
    v_completed   NUMBER;
    v_status      VARCHAR2(20);
BEGIN
    SELECT COUNT(*) INTO v_total_tasks FROM TASK WHERE PRJ_ID = p_prj_no;
    SELECT COUNT(*) INTO v_completed FROM TASK WHERE PRJ_ID = p_prj_no AND STATUS = 'Completed';

    IF v_total_tasks = 0 THEN
        v_status := 'Not Started';
    ELSIF v_completed = v_total_tasks THEN
        v_status := 'Completed';
    ELSIF v_completed > 0 THEN
        v_status := 'In Progress';
    ELSE
        v_status := 'Pending';
    END IF;

    RETURN v_status;
END;
/
SELECT FN_GET_PROJECT_STATUS('P1') FROM DUAL;
SELECT FN_GET_PROJECT_STATUS('P2') FROM DUAL;
SELECT FN_GET_PROJECT_STATUS('P3') FROM DUAL;
SELECT FN_GET_PROJECT_STATUS('P4') FROM DUAL;
SELECT FN_GET_PROJECT_STATUS('P7') FROM DUAL;
CREATE OR REPLACE TRIGGER trg_dependent_delete_log
AFTER DELETE ON department
FOR EACH ROW
BEGIN

    INSERT INTO dependent_delete_log
    (
        depid,
        empno,
        departmentname,
        gender,
        dateofbirth,
        relationship,
        nompct,
        medcover,
        deleted_date,
        deleted_by
    )
    VALUES
    (
        :OLD.depid,
        :OLD.empno,
        :OLD.departmentname,
        :OLD.gender,
        :OLD.dateofbirth,
        :OLD.relationship,
        :OLD.nompct,
        :OLD.medcover,
        SYSDATE,
        USER
    );

END;
/
CREATE OR REPLACE TRIGGER trg_prevent_salary_decrease
BEFORE UPDATE OF salary ON emp
FOR EACH ROW
BEGIN

    IF :NEW.salary < :OLD.salary THEN
        RAISE_APPLICATION_ERROR(-20010,'ERROR: Employee salary cannot be decreased.');
    END IF;

END;
/

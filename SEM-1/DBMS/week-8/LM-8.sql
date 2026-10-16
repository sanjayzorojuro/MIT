CREATE OR REPLACE TRIGGER trg_no_salary_decrease
 BEFORE UPDATE OF salary ON emp
 FOR EACH ROW
 BEGIN
     IF :NEW.salary < :OLD.salary THEN
         RAISE_APPLICATION_ERROR(
             -20011,
             'Salary decrease is not allowed.'
         );
     END IF;
 END;
 /

create or replace TRIGGER t_proj_fund
BEFORE UPDATE OF proj_fund ON proj
FOR EACH ROW
DECLARE
    proj_duration NUMBER;
    lapsed_duration  NUMBER;
    additional_fund  NUMBER;
    eligible_fund    NUMBER;
BEGIN

    additional_fund := :NEW.proj_fund - :OLD.proj_fund;

    IF additional_fund > 0 THEN
        proj_duration := :NEW.enddate - :NEW.startdate;
        lapsed_duration := CURRENT_DATE - :NEW.startdate;


        IF proj_duration > 0 THEN

            IF lapsed_duration < (proj_duration * 0.50) THEN

                eligible_fund := additional_fund * 0.70;

                DBMS_OUTPUT.PUT_LINE('You are eligible for Rs. ' ||eligible_fund || '(70% of requested)');

            ELSE

                eligible_fund := additional_fund * 0.40;

                DBMS_OUTPUT.PUT_LINE('You are eligible for Rs. ' ||eligible_fund ||' (40% of requested)');

            END IF;
        END IF;
    END IF;
END;
/


declare
	prin number;
	rate number;
	year number;
	intrest number;
begin 	
	prin := &principle;
	rate := &rate;
	year := &duration;
	
	if prin <= 1000 then
		DBMS_OUTPUT.PUT_LINE('Principle amount must be greater than 1000');
	elsif rate < 5 then
		DBMS_OUTPUT.PUT_LINE('Rate of intrest must atleast be 5');
	elsif year < 1 then
		DBMS_OUTPUT.PUT_LINE('Year should be at least 1');
	else
		intrest := (prin * rate * year) / 100;

        	DBMS_OUTPUT.PUT_LINE('Principle: ' || prin);
        	DBMS_OUTPUT.PUT_LINE('Interest Rate: ' ||rate|| '%');
        	DBMS_OUTPUT.PUT_LINE('Duration: ' ||year|| ' years');
        	DBMS_OUTPUT.PUT_LINE('Interest: ' ||intrest);
    	end if;

EXCEPTION
    WHEN OTHERS THEN
        DBMS_OUTPUT.PUT_LINE(SQLERRM);
END;
/

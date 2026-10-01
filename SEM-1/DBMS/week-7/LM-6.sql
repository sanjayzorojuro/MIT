declare
	cursor c is select p.dno,p.projno,p.projname,t.taskid,t.taskname,t.startdate,t.enddate,t.status from proj p left join task t on p.dno = t.dno and p.projno = t.projid order by p.dno,p.projno,t.taskid;

begin
	for rec in c loop
		DBMS_OUTPUT.PUT_LINE(chr(10) || 'Project :'||rec.projname || '(' ||rec.projno || ')');
		
		if rec.taskid is not null then 
			DBMS_OUTPUT.PUT_LINE('Task id : ' ||rec.taskid);
			DBMS_OUTPUT.PUT_LINE('Task name:' ||rec.taskname);
			DBMS_OUTPUT.PUT_LINE('Start date:' ||to_char(rec.startdate,'dd-mon-yyyy'));
			DBMS_OUTPUT.PUT_LINE('End date:' ||nvl(to_char(rec.enddate,'dd-mon-yyyy'),'Not completed'));
			DBMS_OUTPUT.PUT_LINE('Status:' ||rec.status);
		else
			DBMS_OUTPUT.PUT_LINE('No task associated with the project.');
		end if;
	end loop;
end;
/

set serveroutput on;
declare
	src bus_route.source%type := '&source';
	dess bus_route.des%type := '&destination';
	reqseat number(4) := &enter_seat;
	rno bus_route.route_no%type;
	price bus_route.tariff%type;
	total number(7);
	final number(4);

	cursor c(c_src varchar,c_dest varchar,c_reqseat number)is select route_no,tariff,source,des into rno,price,src,dess from bus_route where source = c_src and des = c_dest and seats>= c_reqseat ;

begin
	for rec in c(src,dess,reqseat) loop
		dbms_output.put_line('Route number:'||rec.route_no);
		dbms_output.put_line('Tariff:'||rec.tariff);
		total := rec.tariff*reqseat;
		dbms_output.put_line('Total price:'||total);

	end loop;
	
end;
/
	
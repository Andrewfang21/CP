program Jawbreaker_4;
var
   matriks1, matriks2, matriks3 : array[0..30, 0..30] of integer;
   i,j,k,l,M,N,jum,jum2 : integer;
   ans, choose : longint;
   
procedure swap(var  a,b: integer);
 var
  temp:longint;
 begin
  temp:=a;
  a:=b;
  b:=temp;
 end;
   
procedure floodfill(x, y, ch, tipe : integer) ;
begin
     if (x >= 1) and (y >= 1) and (x <= M) and (y <= N) and (matriks1[x, y] = ch) then
     begin
          matriks1[x, y] := 0;
          if (tipe=1) then inc(jum)
          else
          if (tipe=2) then inc(jum2);
          
          floodfill(x, y-1, ch, tipe);
          floodfill(x+1, y, ch, tipe);
          floodfill(x, y+1, ch, tipe);
          floodfill(x-1, y, ch, tipe);
     end;
end;

Procedure runtuh;
 var
  temp1,temp2,temp3:longint;
 begin
  for temp1:= 1 to N do begin
   for temp2:= 1 to M do begin
    if (matriks1[temp2,temp1]=0) then
     begin
      temp3:=temp2;
      while (temp3>1) do
       begin
        swap(matriks1[temp3,temp1],matriks1[temp3-1,temp1]);
        if (temp3<>1) then dec(temp3);
       end;
     end;
    end;
   end;
  end;       

begin
     readln(M, N);
     for i:=1 to M do
		for j:=1 to N do
			read(matriks1[i, j]);
     
     matriks2:=matriks1;
     ans := 0;
     for i:=1 to M do
		for j:=1 to N do
		begin
		  matriks1:=matriks2;
          if (matriks1[i, j]<>0) then
			begin
			jum := 0;
			choose := 0;
			matriks1:=matriks2;
			floodfill(i, j, matriks1[i, j], 1);
			runtuh;
            
			matriks3:=matriks1;
 
			if (jum<>1) then
			begin
			for k:=1 to M do
				for l:=1 to N do
				begin
					if (matriks1[k, l] <> 0) then
                    begin
                         jum2:= 0;
                         matriks1:=matriks3;
                         floodfill(k, l, matriks1[k, l], 2);
                         
                         if (choose < jum2) then
                         choose := jum2;  
                    end;
               end;
               end;
               if jum*(jum-1) + choose*(choose-1) > ans then
               ans := jum*(jum-1) + choose*(choose-1);
			end;
		end;
     writeln(ans);
end.

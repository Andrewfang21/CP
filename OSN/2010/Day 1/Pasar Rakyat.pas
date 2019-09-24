var
 N,i,p,kali,c:longint;
 desa:array[1..40] of longint;

Function cek(a:longint):boolean;
 var
  i:longint;
  iseng:boolean;
 begin
  iseng:=false;
  for i:= 1 to N do
   if (desa[i] mod a=0) then iseng:=true;
  cek:=iseng;
 end;

begin
 readln(N);
 for i:= 1 to N do
  read(desa[i]);
 p:=2; kali:=1;
 for c:= 1 to 200000 do
  begin
   if (cek(p)) then
    begin
     kali:=kali*p;
     for i:= 1 to N do
     begin
      if (desa[i] mod p=0) then
       desa[i]:=desa[i] div p;
     end;
    end else
   inc(p);
  end;
 writeln(kali);
end.

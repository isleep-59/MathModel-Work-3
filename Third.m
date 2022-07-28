clear
clc

C = [20 0; 50 0; 160 0; 200 50; 120 100; 35 100; 10 100; 0 25; 50 75; 40 40; 120 40; 115 70];

n = size(C ,1);
%D = zeros(n, n);
%for i=1:n
%    for j=1:n
%        if i ~= j
%            D(i,j) = sqrt((C(i,1)-C(j,1))^2 + (C(i,2)-C(j,2))^2);
%        else
%            D(i,j) = eps;
%        end
%    end
%end

x = C(:,1);
x = x';
y = C(:,2);
y = y';

result = [6 7;6 9;1 2; 5 12; 11 12; 1 8;9 10;2 10;3 11;3 4;9 12];
%result = [6 9;5 12; 11 12; 9 10];
result = result';
axis([0 200 0 100]);
plot(x, y, '*')


for i=1:n-1
    hold on
    plot([x(result(1,i));x(result(2,i))],[y(result(1,i));y(result(2,i))])
end
hold off
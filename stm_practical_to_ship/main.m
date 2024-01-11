% clear
clc
clear all
serial_port = serialport("COM4" , 2000000);
serial_port.UserData = struct(  'currentA', [],...
                            'currentB', [],...
                            'currentC', [],...
                            'busv', [],...
                            'potentiometer', [],...
                            'temperature', []);
serial_port.flush();
pause(1);
% serial_port.configureCallback("byte", 12, @stm_callback);
for i = 1:10
message_bytes = read(serial_port, 6 , "uint16");
% message bytes contains the bytes in the message
% do with it what you wish 
end
clear serial_port
%%

%%

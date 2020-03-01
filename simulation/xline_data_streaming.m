clear all; close all; clc;

s = serialport('COM4', 115200);
configureTerminator(s,"CR");

key = 'Line';

% Create "animated line" plot without any data
fig = figure('Name', 'xline line algorithm')
fig.Units = 'normalized'
fig.Position = [0.1 0.2 0.75 0.6];

    
h = animatedline('Color','r','LineWidth',1);
h2 = animatedline('LineWidth', 3);
ylim([-8000, 8000]);
grid on

% Keep updating data
k = 0;
while 1 
   data = char(string(readline(s)));
   data(strfind(data, '=')) = [];
   index = strfind(data, key);
   sensor_value = sscanf(data(index(1) + length(key):end), '%d', 1)
  
   
   %Draw black line and then sensor values on top
   addpoints(h2, k, 0);
   addpoints(h, k, sensor_value);

   
   xlim([k-100, k+100]);
   drawnow
   k = k + 1;
end

%%delete(s)
% Parameters.m
%
% Model:        Faulhaber 2237-006-CXR
% Datasheet:    https://www.faulhaber.com/fileadmin/Import/Media/EN_2237_CXR_DFF.pdf
% =========================================================================
clc;
% Motor
R       = 0.85;             % Resistance [R]
L       = 35e-6;            % Inductance [H]
k_e     = 0.78e-3;          % Back-emf constant [V/min^-1]
k_m     = 7.44e-3;          % Torque constant [N*m/A] 

% Due to graphite brushes the resistance is not very accurate
% Hence the model uses no load speed and stall torque
n_0     = 6900;             % No load speed [rpm]
i_0     = 0.124;            % No load current [A]
u_0     = 6;                % Voltage for no load measurements [V]
M_H     = 47.2e-3;          % Stall torque


J       = 3.1;             % Rotor inertia [g*cm^2]
J       = 1e-7 * J;         % Rotor inertia [kg*m^2] 
u_max   = 12;               % Maximum voltage [V]

% Encoder
LPR     = 1024;             % Lines per revolution
CPR     = LPR * 4;          % Counts per revolution
 
% Robot
n       = 1;                % Gear ratio
d       = 26;               % Wheel diameter [mm]
r       = d/2;              % Wheel radius [mm]
m_tot 	= 68*2+13*2 + 25 + 13 + 20; % motors + wheels + batt + sensor stick + PCB              % Weight of robot [g]
m       = m_tot/2;
a       = 2;                % Acceleration

% H-Bride
R_on = 0.3;                 % On resistance of H-bridge
R_d = 0.1;                  % Freewheeling diode resistance of H-bridge

% Electrics
f       = 100e3;             % PWM frequency [Hz]

% Simul ation
u_time  = 0.1;              % Time of voltage step
u_step  = 6;                % Voltage step for simulation
t_samp  = 0.001;            % Sample time for the system (1000 HZ)
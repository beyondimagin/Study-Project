1) CAN.dbc File

Make sure to have appropriate CAN.dbc file with all required signals and ID’s. 

2) Make sure main workspace is added to the path.

To “add to path” right click on workspace which include all the Simulink model and folder containing fault injection block. Then select add to path with folders and subfolders.

3) Check available CAN HW devices on system using MATLAB command: 

>canHWInfo

4) Load Accel, Epoch, GPS Speed, and Vehicle Speed data sample into the workspace:

>load Accel

>load Epoch

>load GPS_Speed

>load Vehicle_Speed

This will load all the data samples along with its timestamp for transmission of data.

This data from workspace is used as data parameter in Simulink block “From Workspace” for continuous transmission of signal.

**Simulink Setup:**

CAN model is implemented using Vehicle Network Toolbox.

1) CAN Configuration Block:

* Device: MathWorks Virtual Channel 1

* Bus Speed: 500000

* Acknowledge mode: Normal

**CAN Transmission Model**

2) From Workspace:

    We already loaded data samples in workspace from point 4.

* Data: From workspace (Here it is Epoch, GPS_Speed, Accel, and Vehicle_Speed)

* Output data type: double

* From output after final data value by: Holding final value

3) CAN Pack Block:

    Used to pack data into CAN message format

* Data is input as: CANdb specified signals

* CANdb file: select .dbc file in this case SPMD.dbc is used.

* Output as bus: check

4) CAN Transmit Block:

* Device: MathWorks Virtual Channel 1

**CAN Reception Model**

1) CAN Receive Block:

* Device: MathWorks Virtual Channel 1

* If you want to filter out some specific IDs use IDs filter setting.

* Sample time to: -1

2) Add Function Block from Ports & Subsystems

3) Add CAN Unpack Block inside function block.

* Data to output as: CANdb specified signals

* CANdb file: select .dbc file in this case SPMD.dbc is used.

Check all connections.

Save and run Simulation.

For snapshot please refer to Study Project Final Report.pdf section 9. Usage Instructions





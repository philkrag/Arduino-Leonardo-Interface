/*

// /////////////////////////////////////////////////////////////////////// COPYRIGHT NOTICE
// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
// You should have received a copy of the GNU General Public License
// along with Pip-Project.  If not, see <http://www.gnu.org/licenses/>.
// /////////////////////////////////////////////////////////////////////// COPYRIGHT NOTICE

// /////////////////////////////////////////////////////////////////////// VERSION CONTROL
// PAGE CREATED BY: Phillip Kraguljac
// PAGE CREATED DATE: 2018-07-07
// DATE       || NAME           || MODIFICATION
// 2018-07-07   || Phillip Kraguljac    || Created.
// /////////////////////////////////////////////////////////////////////// VERSION CONTROL

*/

int CPU_Cycle = 0;

int Device_ID = 0;
int Device_Version = 1;

String Serial_Return_String = "test";

int Input_1_Value = 0;
int Input_1_MValue = 0;

int Input_2_Value = 0;
int Input_2_MValue = 0;

int Input_3_Value = 0;
int Input_3_MValue = 0;

int Input_4_Value = 0;
int Input_4_MValue = 0;

int Input_5_Value = 0;
int Input_5_MValue = 0;

int Input_6_Value = 0;
int Input_6_MValue = 0;

int Output_1_Value = 0;
int Output_2_Value = 0;
int Output_3_Value = 0;
int Output_4_Value = 0;
int Output_5_Value = 0;
int Output_6_Value = 0;

bool Send_Serial_Flag = false;

void setup() {

Serial.begin(9600);

pinMode(2, INPUT);
pinMode(3, INPUT); // PWM
pinMode(4, INPUT);
pinMode(5, INPUT); // PWM
pinMode(6, INPUT); // PWM
pinMode(7, INPUT);
pinMode(8, OUTPUT);
pinMode(9, OUTPUT); // PWM
pinMode(10, OUTPUT); // PWM
pinMode(11, OUTPUT); // PWM
pinMode(12, OUTPUT);
pinMode(13, OUTPUT); // PWM

pinMode(LED_BUILTIN, OUTPUT);

}


void loop() {

CPU_Cycle = CPU_Cycle + 1;

Send_Serial_Flag = false;

Input_1_Value = digitalRead(2);
Input_2_Value = digitalRead(3);
Input_3_Value = digitalRead(4);
Input_4_Value = digitalRead(5);
Input_5_Value = digitalRead(6);
Input_6_Value = digitalRead(7);

//if(CPU_Cycle==10){Input_1_Value = Input_1_Value+1;}

if(Input_1_MValue!=Input_1_Value){ Send_Serial_Flag = true; Input_1_MValue = Input_1_Value; }
if(Input_2_MValue!=Input_2_Value){ Send_Serial_Flag = true; Input_2_MValue = Input_1_Value; }
if(Input_3_MValue!=Input_3_Value){ Send_Serial_Flag = true; Input_3_MValue = Input_1_Value; }
if(Input_4_MValue!=Input_4_Value){ Send_Serial_Flag = true; Input_4_MValue = Input_1_Value; }
if(Input_5_MValue!=Input_5_Value){ Send_Serial_Flag = true; Input_5_MValue = Input_1_Value; }
if(Input_6_MValue!=Input_6_Value){ Send_Serial_Flag = true; Input_6_MValue = Input_1_Value; }


if(Send_Serial_Flag == true){
Serial_Return_String = "";

Serial_Return_String = Serial_Return_String + "CYC:" + Add_Prefix(CPU_Cycle) + ";";
Serial_Return_String = Serial_Return_String + "ID:" + Add_Prefix(Device_ID) + ";";
Serial_Return_String = Serial_Return_String + "VER:" + Add_Prefix(Device_Version) + ";";

Serial_Return_String = Serial_Return_String + "I1:" + Add_Prefix(Input_1_Value) + ";";
Serial_Return_String = Serial_Return_String + "I2:" + Add_Prefix(Input_2_Value) + ";";
Serial_Return_String = Serial_Return_String + "I3:" + Add_Prefix(Input_3_Value) + ";";
Serial_Return_String = Serial_Return_String + "I4:" + Add_Prefix(Input_4_Value) + ";";
Serial_Return_String = Serial_Return_String + "I5:" + Add_Prefix(Input_5_Value) + ";";
Serial_Return_String = Serial_Return_String + "I6:" + Add_Prefix(Input_6_Value) + ";";

Serial_Return_String = Serial_Return_String + "O1:" + Add_Prefix(Output_1_Value) + ";";
Serial_Return_String = Serial_Return_String + "O2:" + Add_Prefix(Output_2_Value) + ";";
Serial_Return_String = Serial_Return_String + "O3:" + Add_Prefix(Output_3_Value) + ";";
Serial_Return_String = Serial_Return_String + "O4:" + Add_Prefix(Output_4_Value) + ";";
Serial_Return_String = Serial_Return_String + "O5:" + Add_Prefix(Output_5_Value) + ";";
Serial_Return_String = Serial_Return_String + "O6:" + Add_Prefix(Output_6_Value) + ";";

Serial.println(Serial_Return_String);
}


delay(1);        // Stability

if(CPU_Cycle>=100){CPU_Cycle=0;} // Cycle Indication
  
}

// THE FOLLOWING IS FOR ADDING '0' PREFIX TO SERIAL STRING(S)
String Add_Prefix(int Inspected_Value){
String Return_String;
if(Inspected_Value<10){Return_String="00"+String(Inspected_Value);}
if(Inspected_Value>=10&&Inspected_Value<100){Return_String="0"+String(Inspected_Value);}
if(Inspected_Value>=100&&Inspected_Value<1000){Return_String=String(Inspected_Value);}
if(Inspected_Value>=1000){Return_String="xxx";}
return Return_String;
}

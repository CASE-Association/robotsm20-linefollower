<?xml version="1.0" encoding="utf-8"?>
<!DOCTYPE eagle SYSTEM "eagle.dtd">
<eagle version="9.5.2">
<drawing>
<settings>
<setting alwaysvectorfont="no"/>
<setting verticaltext="up"/>
</settings>
<grid distance="0.1" unitdist="inch" unit="inch" style="lines" multiple="1" display="no" altdistance="0.01" altunitdist="inch" altunit="inch"/>
<layers>
<layer number="1" name="Top" color="4" fill="1" visible="no" active="no"/>
<layer number="2" name="Route2" color="16" fill="1" visible="no" active="no"/>
<layer number="3" name="Route3" color="17" fill="1" visible="no" active="no"/>
<layer number="4" name="Route4" color="18" fill="1" visible="no" active="no"/>
<layer number="5" name="Route5" color="19" fill="1" visible="no" active="no"/>
<layer number="6" name="Route6" color="25" fill="1" visible="no" active="no"/>
<layer number="7" name="Route7" color="26" fill="1" visible="no" active="no"/>
<layer number="8" name="Route8" color="27" fill="1" visible="no" active="no"/>
<layer number="9" name="Route9" color="28" fill="1" visible="no" active="no"/>
<layer number="10" name="Route10" color="29" fill="1" visible="no" active="no"/>
<layer number="11" name="Route11" color="30" fill="1" visible="no" active="no"/>
<layer number="12" name="Route12" color="20" fill="1" visible="no" active="no"/>
<layer number="13" name="Route13" color="21" fill="1" visible="no" active="no"/>
<layer number="14" name="Route14" color="22" fill="1" visible="no" active="no"/>
<layer number="15" name="Route15" color="23" fill="1" visible="no" active="no"/>
<layer number="16" name="Bottom" color="1" fill="1" visible="no" active="no"/>
<layer number="17" name="Pads" color="2" fill="1" visible="no" active="no"/>
<layer number="18" name="Vias" color="2" fill="1" visible="no" active="no"/>
<layer number="19" name="Unrouted" color="6" fill="1" visible="no" active="no"/>
<layer number="20" name="Dimension" color="24" fill="1" visible="no" active="no"/>
<layer number="21" name="tPlace" color="7" fill="1" visible="no" active="no"/>
<layer number="22" name="bPlace" color="7" fill="1" visible="no" active="no"/>
<layer number="23" name="tOrigins" color="15" fill="1" visible="no" active="no"/>
<layer number="24" name="bOrigins" color="15" fill="1" visible="no" active="no"/>
<layer number="25" name="tNames" color="7" fill="1" visible="no" active="no"/>
<layer number="26" name="bNames" color="7" fill="1" visible="no" active="no"/>
<layer number="27" name="tValues" color="7" fill="1" visible="no" active="no"/>
<layer number="28" name="bValues" color="7" fill="1" visible="no" active="no"/>
<layer number="29" name="tStop" color="7" fill="3" visible="no" active="no"/>
<layer number="30" name="bStop" color="7" fill="6" visible="no" active="no"/>
<layer number="31" name="tCream" color="7" fill="4" visible="no" active="no"/>
<layer number="32" name="bCream" color="7" fill="5" visible="no" active="no"/>
<layer number="33" name="tFinish" color="6" fill="3" visible="no" active="no"/>
<layer number="34" name="bFinish" color="6" fill="6" visible="no" active="no"/>
<layer number="35" name="tGlue" color="7" fill="4" visible="no" active="no"/>
<layer number="36" name="bGlue" color="7" fill="5" visible="no" active="no"/>
<layer number="37" name="tTest" color="7" fill="1" visible="no" active="no"/>
<layer number="38" name="bTest" color="7" fill="1" visible="no" active="no"/>
<layer number="39" name="tKeepout" color="4" fill="11" visible="no" active="no"/>
<layer number="40" name="bKeepout" color="1" fill="11" visible="no" active="no"/>
<layer number="41" name="tRestrict" color="4" fill="10" visible="no" active="no"/>
<layer number="42" name="bRestrict" color="1" fill="10" visible="no" active="no"/>
<layer number="43" name="vRestrict" color="2" fill="10" visible="no" active="no"/>
<layer number="44" name="Drills" color="7" fill="1" visible="no" active="no"/>
<layer number="45" name="Holes" color="7" fill="1" visible="no" active="no"/>
<layer number="46" name="Milling" color="3" fill="1" visible="no" active="no"/>
<layer number="47" name="Measures" color="7" fill="1" visible="no" active="no"/>
<layer number="48" name="Document" color="7" fill="1" visible="no" active="no"/>
<layer number="49" name="Reference" color="7" fill="1" visible="no" active="no"/>
<layer number="51" name="tDocu" color="7" fill="1" visible="no" active="no"/>
<layer number="52" name="bDocu" color="7" fill="1" visible="no" active="no"/>
<layer number="88" name="SimResults" color="9" fill="1" visible="yes" active="yes"/>
<layer number="89" name="SimProbes" color="9" fill="1" visible="yes" active="yes"/>
<layer number="90" name="Modules" color="5" fill="1" visible="yes" active="yes"/>
<layer number="91" name="Nets" color="2" fill="1" visible="yes" active="yes"/>
<layer number="92" name="Busses" color="1" fill="1" visible="yes" active="yes"/>
<layer number="93" name="Pins" color="2" fill="1" visible="no" active="yes"/>
<layer number="94" name="Symbols" color="4" fill="1" visible="yes" active="yes"/>
<layer number="95" name="Names" color="7" fill="1" visible="yes" active="yes"/>
<layer number="96" name="Values" color="7" fill="1" visible="yes" active="yes"/>
<layer number="97" name="Info" color="7" fill="1" visible="yes" active="yes"/>
<layer number="98" name="Guide" color="6" fill="1" visible="yes" active="yes"/>
</layers>
<schematic xreflabel="%F%N/%S.%C%R" xrefpart="/%S.%C%R">
<libraries>
<library name="MotorDriver" urn="urn:adsk.eagle:library:17561913">
<packages>
<package name="SON127P600X500X90-9T230X400N" urn="urn:adsk.eagle:footprint:17561896/1" library_version="2" library_locally_modified="yes">
<description>8-SON (DFN), 1.27 mm pitch, 5.00 X 6.00 X 0.90 mm body, 4.00 X 2.30 mm thermal pad
&lt;p&gt;8-pin SON (DFN) package with 1.27 mm pitch with body size 5.00 X 6.00 X 0.90 mm and thermal pad size 4.00 X 2.30 mm&lt;/p&gt;</description>
<circle x="-3.529" y="2.626" radius="0.25" width="0" layer="21"/>
<wire x1="-3.025" y1="2.376" x2="-3.025" y2="2.525" width="0.12" layer="21"/>
<wire x1="-3.025" y1="2.525" x2="3.025" y2="2.525" width="0.12" layer="21"/>
<wire x1="3.025" y1="2.525" x2="3.025" y2="2.376" width="0.12" layer="21"/>
<wire x1="-3.025" y1="-2.376" x2="-3.025" y2="-2.525" width="0.12" layer="21"/>
<wire x1="-3.025" y1="-2.525" x2="3.025" y2="-2.525" width="0.12" layer="21"/>
<wire x1="3.025" y1="-2.525" x2="3.025" y2="-2.376" width="0.12" layer="21"/>
<wire x1="3.025" y1="-2.525" x2="-3.025" y2="-2.525" width="0.12" layer="51"/>
<wire x1="-3.025" y1="-2.525" x2="-3.025" y2="2.525" width="0.12" layer="51"/>
<wire x1="-3.025" y1="2.525" x2="3.025" y2="2.525" width="0.12" layer="51"/>
<wire x1="3.025" y1="2.525" x2="3.025" y2="-2.525" width="0.12" layer="51"/>
<smd name="1" x="-2.8364" y="1.905" dx="1.0273" dy="0.434" layer="1" roundness="100"/>
<smd name="2" x="-2.8364" y="0.635" dx="1.0273" dy="0.434" layer="1" roundness="100"/>
<smd name="3" x="-2.8364" y="-0.635" dx="1.0273" dy="0.434" layer="1" roundness="100"/>
<smd name="4" x="-2.8364" y="-1.905" dx="1.0273" dy="0.434" layer="1" roundness="100"/>
<smd name="5" x="2.8364" y="-1.905" dx="1.0273" dy="0.434" layer="1" roundness="100"/>
<smd name="6" x="2.8364" y="-0.635" dx="1.0273" dy="0.434" layer="1" roundness="100"/>
<smd name="7" x="2.8364" y="0.635" dx="1.0273" dy="0.434" layer="1" roundness="100"/>
<smd name="8" x="2.8364" y="1.905" dx="1.0273" dy="0.434" layer="1" roundness="100"/>
<smd name="9" x="0" y="0" dx="2.3" dy="4" layer="1" thermals="no"/>
<text x="0" y="3.511" size="1.27" layer="25" align="bottom-center">&gt;NAME</text>
<text x="0" y="-3.16" size="1.27" layer="27" align="top-center">&gt;VALUE</text>
</package>
</packages>
<packages3d>
<package3d name="SON127P600X500X90-9T230X400N" urn="urn:adsk.eagle:package:17561785/3" type="model" library_version="2" library_locally_modified="yes">
<description>8-SON (DFN), 1.27 mm pitch, 5.00 X 6.00 X 0.90 mm body, 4.00 X 2.30 mm thermal pad
&lt;p&gt;8-pin SON (DFN) package with 1.27 mm pitch with body size 5.00 X 6.00 X 0.90 mm and thermal pad size 4.00 X 2.30 mm&lt;/p&gt;</description>
<packageinstances>
<packageinstance name="SON127P600X500X90-9T230X400N"/>
</packageinstances>
</package3d>
</packages3d>
<symbols>
<symbol name="TC4426-MOSFET-GATE-DRIVER" library_version="2" library_locally_modified="yes">
<pin name="INA" x="-12.7" y="0" length="middle" direction="in"/>
<pin name="INB" x="-12.7" y="-5.08" length="middle" direction="in"/>
<pin name="!OUTA!" x="12.7" y="0" length="middle" direction="out" rot="R180"/>
<pin name="!OUTB!" x="12.7" y="-5.08" length="middle" direction="out" rot="R180"/>
<pin name="GND" x="-12.7" y="5.08" length="middle" direction="pwr"/>
<pin name="VDD" x="12.7" y="5.08" length="middle" direction="pwr" rot="R180"/>
<wire x1="-7.62" y1="10.16" x2="-7.62" y2="-10.16" width="0.1524" layer="94"/>
<wire x1="-7.62" y1="-10.16" x2="7.62" y2="-10.16" width="0.1524" layer="94"/>
<wire x1="7.62" y1="-10.16" x2="7.62" y2="10.16" width="0.1524" layer="94"/>
<wire x1="7.62" y1="10.16" x2="-7.62" y2="10.16" width="0.1524" layer="94"/>
<text x="-5.08" y="10.16" size="1.778" layer="95">&gt;NAME</text>
<text x="-5.08" y="-12.7" size="1.778" layer="96">&gt;VALUE</text>
</symbol>
</symbols>
<devicesets>
<deviceset name="TC4426VMF" library_version="2" library_locally_modified="yes">
<description>&lt;h1&gt;TC4426VMF&lt;/h1&gt;
&lt;a href="https://www.mouser.se/datasheet/2/268/21422c-73495.pdf"&gt;Datasheet&lt;/a&gt;
&lt;br /&gt;
Part number 
&lt;br /&gt;
&lt;i&gt;Mfr:&lt;/i&gt; TC4426VMF &lt;br /&gt;
&lt;i&gt;Mouser: &lt;/i&gt; 579-TC4426VMF &lt;br /&gt;</description>
<gates>
<gate name="G$1" symbol="TC4426-MOSFET-GATE-DRIVER" x="0" y="0"/>
</gates>
<devices>
<device name="" package="SON127P600X500X90-9T230X400N">
<connects>
<connect gate="G$1" pin="!OUTA!" pad="7"/>
<connect gate="G$1" pin="!OUTB!" pad="5"/>
<connect gate="G$1" pin="GND" pad="1 3 8 9"/>
<connect gate="G$1" pin="INA" pad="2"/>
<connect gate="G$1" pin="INB" pad="4"/>
<connect gate="G$1" pin="VDD" pad="6"/>
</connects>
<package3dinstances>
<package3dinstance package3d_urn="urn:adsk.eagle:package:17561785/3"/>
</package3dinstances>
<technologies>
<technology name=""/>
</technologies>
</device>
</devices>
</deviceset>
</devicesets>
</library>
<library name="frames" urn="urn:adsk.eagle:library:229">
<description>&lt;b&gt;Frames for Sheet and Layout&lt;/b&gt;</description>
<packages>
</packages>
<symbols>
<symbol name="A3L-LOC" urn="urn:adsk.eagle:symbol:13881/1" library_version="1">
<wire x1="288.29" y1="3.81" x2="342.265" y2="3.81" width="0.1016" layer="94"/>
<wire x1="342.265" y1="3.81" x2="373.38" y2="3.81" width="0.1016" layer="94"/>
<wire x1="373.38" y1="3.81" x2="383.54" y2="3.81" width="0.1016" layer="94"/>
<wire x1="383.54" y1="3.81" x2="383.54" y2="8.89" width="0.1016" layer="94"/>
<wire x1="383.54" y1="8.89" x2="383.54" y2="13.97" width="0.1016" layer="94"/>
<wire x1="383.54" y1="13.97" x2="383.54" y2="19.05" width="0.1016" layer="94"/>
<wire x1="383.54" y1="19.05" x2="383.54" y2="24.13" width="0.1016" layer="94"/>
<wire x1="288.29" y1="3.81" x2="288.29" y2="24.13" width="0.1016" layer="94"/>
<wire x1="288.29" y1="24.13" x2="342.265" y2="24.13" width="0.1016" layer="94"/>
<wire x1="342.265" y1="24.13" x2="383.54" y2="24.13" width="0.1016" layer="94"/>
<wire x1="373.38" y1="3.81" x2="373.38" y2="8.89" width="0.1016" layer="94"/>
<wire x1="373.38" y1="8.89" x2="383.54" y2="8.89" width="0.1016" layer="94"/>
<wire x1="373.38" y1="8.89" x2="342.265" y2="8.89" width="0.1016" layer="94"/>
<wire x1="342.265" y1="8.89" x2="342.265" y2="3.81" width="0.1016" layer="94"/>
<wire x1="342.265" y1="8.89" x2="342.265" y2="13.97" width="0.1016" layer="94"/>
<wire x1="342.265" y1="13.97" x2="383.54" y2="13.97" width="0.1016" layer="94"/>
<wire x1="342.265" y1="13.97" x2="342.265" y2="19.05" width="0.1016" layer="94"/>
<wire x1="342.265" y1="19.05" x2="383.54" y2="19.05" width="0.1016" layer="94"/>
<wire x1="342.265" y1="19.05" x2="342.265" y2="24.13" width="0.1016" layer="94"/>
<text x="344.17" y="15.24" size="2.54" layer="94">&gt;DRAWING_NAME</text>
<text x="344.17" y="10.16" size="2.286" layer="94">&gt;LAST_DATE_TIME</text>
<text x="357.505" y="5.08" size="2.54" layer="94">&gt;SHEET</text>
<text x="343.916" y="4.953" size="2.54" layer="94">Sheet:</text>
<frame x1="0" y1="0" x2="387.35" y2="260.35" columns="8" rows="5" layer="94"/>
</symbol>
</symbols>
<devicesets>
<deviceset name="A3L-LOC" urn="urn:adsk.eagle:component:13942/1" prefix="FRAME" uservalue="yes" library_version="1">
<description>&lt;b&gt;FRAME&lt;/b&gt;&lt;p&gt;
DIN A3, landscape with location and doc. field</description>
<gates>
<gate name="G$1" symbol="A3L-LOC" x="0" y="0"/>
</gates>
<devices>
<device name="">
<technologies>
<technology name=""/>
</technologies>
</device>
</devices>
</deviceset>
</devicesets>
</library>
</libraries>
<attributes>
</attributes>
<variantdefs>
</variantdefs>
<classes>
<class number="0" name="default" width="0" drill="0">
</class>
</classes>
<parts>
<part name="U$1" library="MotorDriver" library_urn="urn:adsk.eagle:library:17561913" deviceset="TC4426VMF" device="" package3d_urn="urn:adsk.eagle:package:17561785/3"/>
<part name="U$2" library="MotorDriver" library_urn="urn:adsk.eagle:library:17561913" deviceset="TC4426VMF" device="" package3d_urn="urn:adsk.eagle:package:17561785/3"/>
<part name="FRAME1" library="frames" library_urn="urn:adsk.eagle:library:229" deviceset="A3L-LOC" device=""/>
</parts>
<sheets>
<sheet>
<plain>
</plain>
<instances>
</instances>
<busses>
</busses>
<nets>
</nets>
</sheet>
<sheet>
<description>&lt;h1&gt; Motor driver&lt;/h1&gt;
&lt;p&gt;A schematic over the motor driver used for the DC motors.&lt;/p&gt;</description>
<plain>
</plain>
<instances>
<instance part="U$1" gate="G$1" x="40.64" y="33.02" smashed="yes">
<attribute name="NAME" x="35.56" y="43.18" size="1.778" layer="95"/>
<attribute name="VALUE" x="35.56" y="20.32" size="1.778" layer="96"/>
</instance>
<instance part="U$2" gate="G$1" x="40.64" y="-2.54" smashed="yes">
<attribute name="NAME" x="35.56" y="7.62" size="1.778" layer="95"/>
<attribute name="VALUE" x="35.56" y="-15.24" size="1.778" layer="96"/>
</instance>
<instance part="FRAME1" gate="G$1" x="-195.58" y="-106.68" smashed="yes">
<attribute name="DRAWING_NAME" x="148.59" y="-91.44" size="2.54" layer="94"/>
<attribute name="LAST_DATE_TIME" x="148.59" y="-96.52" size="2.286" layer="94"/>
<attribute name="SHEET" x="161.925" y="-101.6" size="2.54" layer="94"/>
</instance>
</instances>
<busses>
</busses>
<nets>
</nets>
</sheet>
</sheets>
</schematic>
</drawing>
<compatibility>
<note version="8.2" severity="warning">
Since Version 8.2, EAGLE supports online libraries. The ids
of those online libraries will not be understood (or retained)
with this version.
</note>
<note version="8.3" severity="warning">
Since Version 8.3, EAGLE supports URNs for individual library
assets (packages, symbols, and devices). The URNs of those assets
will not be understood (or retained) with this version.
</note>
<note version="8.3" severity="warning">
Since Version 8.3, EAGLE supports the association of 3D packages
with devices in libraries, schematics, and board files. Those 3D
packages will not be understood (or retained) with this version.
</note>
</compatibility>
</eagle>

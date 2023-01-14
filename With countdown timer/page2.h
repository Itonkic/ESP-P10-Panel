
const char htmlPage2[] PROGMEM = R"=====(
<!DOCTYPE html>
<html>
  <head>
    <meta name="viewport" content="width=device-width, initial-scale=1">
    <style>
      html {
        font-family: Arial;
        display: inline-block;
        margin: 0px auto;
        text-align: center;
      }
      h1 { font-size: 2.0rem; color:#2980b9;}   
      .buttonSend {
        display: inline-block;
        padding: 15px 25px;
        font-size: 24px;
        font-weight: bold;
        cursor: pointer;
        text-align: center;
        text-decoration: none;
        outline: none;
        color: #fff;
        background-color: #4CAF50;
        border: none;
        border-radius: 15px;
        box-shadow: 0 5px #999;
      }
        .buttonSend:hover {background-color: #3e8e41}
        .buttonSend:active {
        background-color: #3e8e41;
        box-shadow: 0 1px #666;
        transform: translateY(4px);
      }
	  .button1 {
        font-size: 0px;
  position: absolute;
  left: 10px;
  top: 10px;
    background:transparent;
    border:none;
    outline:none;
    display:block;
    height:200px;
    width:200px;
    cursor:pointer;
}
    </style>
  </head>

  <body>


  <table style="margin-left:auto;margin-right:auto;">
    <tbody>
      <tr>
        <td>
		</td>
		<td id="plus">Temp - :&nbsp;</td>
        <td><input align="left" type="text" id="TEMPM" name="1st shift start" size = "3" placeholder="°C" >   &nbsp;</td>
      </tr>
      <tr>
        <td></td>
		<td id="minus">Temp +:&nbsp;</td>
        <td><input align="left" type="text" id="TEMPP" name="1st shift start" size = "3" placeholder="°C">   &nbsp;</td>
      </tr>
    </tbody>
  </table>
  

  <table>
  <div>
    <button type="button" class="buttonSend" onclick="temp()"id="test">Update temperature</button>
    </div>
    <script>

      function sendData() {
        var xhttp = new XMLHttpRequest();
        xhttp.open("GET", "setText?TextContents="+"s_"+document.getElementById("duzinataktsat").value+"_"+document.getElementById("duzinataktmin").value+"_"+document.getElementById("duzinataktsec").value+"_");
        xhttp.send(); 
      }
        function send() {
        var xhttp = new XMLHttpRequest();
        xhttp.open("GET", "setText?TextContents="+"t_"+document.getElementById("SRD").value);
        xhttp.send(); 
      }
            function post() {
        var xhttp = new XMLHttpRequest();
xhttp.open("GET", "setText?TextContents="+"k_"+document.getElementById("FSSS").value+"_"+document.getElementById("FSSM").value+"_"+document.getElementById("FSESSSS").value+"_"+document.getElementById("FSESSSM").value+"_"+document.getElementById("SSETSSS").value+"_"+document.getElementById("SSETSSM").value+"_"+document.getElementById("FBFSS").value+"_"+document.getElementById("FBFSM").value+"_"+document.getElementById("ESBES").value+"_"+document.getElementById("ESBEM").value+"_"+document.getElementById("TSBSS").value+"_"+document.getElementById("TSBSM").value+"_"+document.getElementById("SBFSS").value+"_"+document.getElementById("SBFSM").value+"_"+document.getElementById("FBSSSS").value+"_"+document.getElementById("FBSSSM").value+"_"+document.getElementById("TSBES").value+"_"+document.getElementById("TSBEM").value+"_"+document.getElementById("FBEFSS").value+"_"+document.getElementById("FBEFSM").value+"_"+document.getElementById("FBESSS").value+"_"+document.getElementById("FBESSM").value+"_"+document.getElementById("TSES").value+"_"+document.getElementById("TSEM").value+"_"+document.getElementById("SBEFSS").value+"_"+document.getElementById("SBEFSM").value+"_"+document.getElementById("EHSES").value+"_"+document.getElementById("EHSEM").value+"_"+document.getElementById("ALARMS").value+"_");
        xhttp.send(); 
      }
                function shift() {
        var xhttp = new XMLHttpRequest();
xhttp.open("GET", "setText?TextContents="+"y_"+document.getElementById("FSSS").value+"_"+document.getElementById("FSSM").value+"_"+document.getElementById("FSESSSS").value+"_"+document.getElementById("FSESSSM").value+"_"+document.getElementById("SSETSSS").value+"_"+document.getElementById("SSETSSM").value+"_"+document.getElementById("FBFSS").value+"_"+document.getElementById("FBFSM").value+"_"+document.getElementById("ESBES").value+"_"+document.getElementById("ESBEM").value+"_"+document.getElementById("TSBSS").value+"_"+document.getElementById("TSBSM").value+"_"+document.getElementById("SBFSS").value+"_"+document.getElementById("SBFSM").value+"_"+document.getElementById("FBSSSS").value+"_"+document.getElementById("FBSSSM").value+"_"+document.getElementById("TSBES").value+"_"+document.getElementById("TSBEM").value+"_"+document.getElementById("FBEFSS").value+"_"+document.getElementById("FBEFSM").value+"_"+document.getElementById("FBESSS").value+"_"+document.getElementById("FBESSM").value+"_"+document.getElementById("TSES").value+"_"+document.getElementById("TSEM").value+"_"+document.getElementById("SBEFSS").value+"_"+document.getElementById("SBEFSM").value+"_"+document.getElementById("EHSES").value+"_"+document.getElementById("EHSEM").value+"_"+document.getElementById("ALARMS").value+"_");
        xhttp.send(); 
      }
                    function temp() {
        var xhttp = new XMLHttpRequest();
xhttp.open("GET", "setText?TextContents="+"p_"+document.getElementById("TEMPM").value+"_"+document.getElementById("TEMPP").value+"_");
        xhttp.send(); 
      }
	                function test() {
					if(document.getElementById("ALARMM").value =="2412"){
					document.getElementById("TEMPP").style.visibility = "hidden"
					document.getElementById("plus").style.visibility = "hidden"
					document.getElementById("minus").style.visibility = "hidden"
					document.getElementById("TEMPM").style.visibility = "hidden"
					document.getElementById("test").style.visibility = "hidden"
					}
					else if (document.getElementById("ALARMM").value =="2512") {
					document.getElementById("TEMPP").style.visibility = "visible"
					document.getElementById("plus").style.visibility = "visible"
					document.getElementById("minus").style.visibility = "visible"
					document.getElementById("TEMPM").style.visibility = "visible"
					document.getElementById("test").style.visibility = "visible"
					}
	}
    </script>
  </body>
</html>
)=====";

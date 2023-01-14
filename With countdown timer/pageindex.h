
const char MAIN_page[] PROGMEM = R"=====(
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
    <div>
      <h3>Duzina takta</h3>
    <p>Molimo unesite takt:</p>
    <label for="duzinataktsat">Sat:</label>
    <input type="text" id="duzinataktsat" name="duzinataktsat" size = "10" placeholder="hh">
    <label for="duzinataktmin">Min:</label>
    <input type="text" id="duzinataktmin" name="duzinataktmin" size = "10" placeholder="mm">
    <label for="duzinataktsec">Sec:</label>
    <input type="text" id="duzinataktsec" name="duzinataktsec" size = "10" placeholder="sec">
      <br><br>
    </div>

      <div>
      <h3>Alarm</h3>
    <p>Molimo unesite vremena:</p>
    <label align="left" for="FSS">Srednji red display-a: </label>
    <input align="left" type="text" id="SRD" name="Srednji red" size = "30" placeholder=" ">
    <br>
    <br>
    <button type="button" class="buttonSend" onclick="sirenat()">Sirena takta</button>
    <button type="button" class="buttonSend" onclick="sirenapa()">Sirena pauza</button>
      <br><br>
    </div>
  <table style="margin-left:auto;margin-right:auto;">
    <tbody>
<tr>
        <td>1st shift start   :&nbsp;</td>
        <td><input align="left" type="text" id="FSSS" name="FSSS" size = "3" placeholder="hh" value="07">  : &nbsp;</td>
        <td><input align="left" type="text" id="FSSM" name="FSSM" size = "3" placeholder="mm" value="00"> &nbsp;</td>
        <td>1st shift end,2nd shift start   :&nbsp;</td>
        <td><input align="left" type="text" id="FSESSSS" name="1st shift start" size = "3" placeholder="hh" value="15">  : &nbsp;</td>
        <td><input align="left" type="text" id="FSESSSM" name="1st shift start" size = "3" placeholder="mm" value="00"> &nbsp;</td>
        <td>2nd shift end, 3rd shift start   :&nbsp;</td>
        <td><input align="left" type="text" id="SSETSSS" name="1st shift start" size = "3" placeholder="hh" value="23">  : &nbsp;</td>
        <td><input align="left" type="text" id="SSETSSM" name="1st shift start" size = "3" placeholder="mm" value="00"> &nbsp;</td>
      </tr>
      <tr>
        <td>1st break start for 1st shift   :&nbsp;</td>
        <td><input align="left" type="text" id="FBFSS" name="1st shift break start for 1st shift" size = "3" placeholder="hh" value="10">  : &nbsp;</td>
        <td><input align="left" type="text" id="FBFSM" name="1st shift break start for 1st shift" size = "3" placeholder="mm" value="00"> &nbsp;</td>
        <td>EH shift break end   :&nbsp;</td>
        <td><input align="left" type="text" id="ESBES" name="1st shift start" size = "3" placeholder="hh" value="15">  : &nbsp;</td>
        <td><input align="left" type="text" id="ESBEM" name="1st shift start" size = "3" placeholder="mm" value="15"> &nbsp;</td>
        <td>3rd shift break start   :&nbsp;</td>
        <td><input align="left" type="text" id="TSBSS" name="1st shift start" size = "3" placeholder="hh" value="02">  : &nbsp;</td>
        <td><input align="left" type="text" id="TSBSM" name="1st shift start" size = "3" placeholder="mm" value="00"> &nbsp;</td>
      </tr>
      <tr>
        <td>2nd break start for 1st shift   :&nbsp;</td>
        <td><input align="left" type="text" id="SBFSS" name="2nd break start for 1st shift" size = "3" placeholder="hh" value="10">  : &nbsp;</td>
        <td><input align="left" type="text" id="SBFSM" name="2nd break start for 1st shift" size = "3" placeholder="mm" value="00"> &nbsp;</td>
        <td>1st break start for 2nd shift   :&nbsp;</td>
        <td><input align="left" type="text" id="FBSSSS" name="1st shift start" size = "3" placeholder="hh" value="18">  : &nbsp;</td>
        <td><input align="left" type="text" id="FBSSSM" name="1st shift start" size = "3" placeholder="mm" value="00"> &nbsp;</td>
        <td>3rd shift brake end   :&nbsp;</td>
        <td><input align="left" type="text" id="TSBES" name="1st shift start" size = "3" placeholder="hh" value="02">  : &nbsp;</td>
        <td><input align="left" type="text" id="TSBEM" name="1st shift start" size = "3" placeholder="mm" value="30"> &nbsp;</td>
      </tr>
      <tr>
        <td>1st break end for 1st shift   :&nbsp;</td>
        <td><input align="left" type="text" id="FBEFSS" name="1st break end for 1st shift" size = "3" placeholder="hh" value="10">  : &nbsp;</td>
        <td><input align="left" type="text" id="FBEFSM" name="1st break end for 1st shift" size = "3" placeholder="mm" value="30"> &nbsp;</td>
        <td>1st break end for 2nd shift   :&nbsp;</td>
        <td><input align="left" type="text" id="FBESSS" name="1st shift start" size = "3" placeholder="hh" value="18">  : &nbsp;</td>
        <td><input align="left" type="text" id="FBESSM" name="1st shift start" size = "3" placeholder="mm" value="30"> &nbsp;</td>
        <td>3rd shift end   :&nbsp;</td>
        <td><input align="left" type="text" id="TSES" name="1st shift start" size = "3" placeholder="hh" value="07">  : &nbsp;</td>
        <td><input align="left" type="text" id="TSEM" name="1st shift start" size = "3" placeholder="mm" value="00"> &nbsp;</td>
      </tr>
      <tr>
        <td>2nd break end for 1st shift   :&nbsp;</td>
        <td><input align="left" type="text" id="SBEFSS" name="2nd break end for 1st shift" size = "3" placeholder="hh" value="10">  : &nbsp;</td>
        <td><input align="left" type="text" id="SBEFSM" name="2nd break end for 1st shift" size = "3" placeholder="mm" value="30"> &nbsp;</td>
        <td>EH shift end   :&nbsp;</td>
        <td><input align="left" type="text" id="EHSES" name="1st shift start" size = "3" placeholder="hh" value="19">  : &nbsp;</td>
        <td><input align="left" type="text" id="EHSEM" name="1st shift start" size = "3" placeholder="mm" value="00"> &nbsp;</td>
        <td>Alarm duration (sec):&nbsp;</td>
        <td><input align="left" type="text" id="ALARMS" name="Alarm" size = "3" placeholder="sec" value="3"> &nbsp;</td>
        <td><input align="left" type="text" id="ALARMM" name="Alarm" size = "3" placeholder="min"> &nbsp;</td>

      </tr>
      <tr>
        <td>
		<label for="dog-names">1st shift yes/no :  </label> <select name="FYN" id="FYN">
		<option value="1">Yes</option>
		<option value="0">No</option>
		</select>&nbsp;
		</td>
      </tr>
      <tr>
        <td>
		<label for="dog-names">2nd shift yes/no:</label>
		<select name="SYN" id="SYN">
		<option value="0">No</option>
		<option value="1">Yes</option>
		</select>&nbsp;
		</td>
      </tr>
      <tr>
        <td><label for="dog-names">3rd shift yes/no :  </label>
		<select name="TYN" id="TYN">
		<option value="0">No</option>
		<option value="1">Yes</option>
		</select>&nbsp;</td>
      </tr>
    <tr>
        <td><label for="dog-names">12h shift yes/no:  </label> 
		<select name="12H" id="12H">
		<option value="0">No</option>
		<option value="1">Yes</option>
		</select>&nbsp;</td>
      </tr>
    </tbody>
  </table>
  
    <div>
      <button type="button" class="buttonSend" onclick="sendData()">Update takta</button>
    <button type="button" class="buttonSend" onclick="send()">Update Srednjeg reda</button>
    <button type="button" class="buttonSend" onclick="post()" >Update tablice </button> &nbsp;
    </div>
  <table>
<tbody>
     <tr>
        <td><label for="dog-names"></label>&nbsp;</td>
     </tr>

    </tbody>
  </table>
  <div>
      <button type="button" class="buttonSend" onclick="shift()">Update smjena</button>
    </div>
  <div>
    </div>
    <script>
						document.getElementById("TEMPP").style.visibility = "hidden"
					document.getElementById("plus").style.visibility = "hidden"
					document.getElementById("minus").style.visibility = "hidden"
					document.getElementById("TEMPM").style.visibility = "hidden"
					document.getElementById("test").style.visibility = "hidden"
      function sendData() {
        var xhttp = new XMLHttpRequest();
        xhttp.open("GET", "setText?TextContents="+"s_"+document.getElementById("duzinataktsat").value+"_"+document.getElementById("duzinataktmin").value+"_"+document.getElementById("duzinataktsec").value+"_");
        xhttp.send(); 
      }
	        function sirenapa() {
        var xhttp = new XMLHttpRequest();
        xhttp.open("GET", "setText?TextContents="+"w_"+"_");
        xhttp.send(); 
      }
        function send() {
        var xhttp = new XMLHttpRequest();
        xhttp.open("GET", "setText?TextContents="+"t_"+document.getElementById("SRD").value);
        xhttp.send(); 
      }
	    function sirenat() {
        var xhttp = new XMLHttpRequest();
        xhttp.open("GET", "setText?TextContents="+"q_");
        xhttp.send(); 
      }
            function post() {
        var xhttp = new XMLHttpRequest();
xhttp.open("GET", "setText?TextContents="+"k_"+document.getElementById("FSSS").value+"_"+document.getElementById("FSSM").value+"_"+document.getElementById("FSESSSS").value+"_"+document.getElementById("FSESSSM").value+"_"+document.getElementById("SSETSSS").value+"_"+document.getElementById("SSETSSM").value+"_"+document.getElementById("FBFSS").value+"_"+document.getElementById("FBFSM").value+"_"+document.getElementById("ESBES").value+"_"+document.getElementById("ESBEM").value+"_"+document.getElementById("TSBSS").value+"_"+document.getElementById("TSBSM").value+"_"+document.getElementById("SBFSS").value+"_"+document.getElementById("SBFSM").value+"_"+document.getElementById("FBSSSS").value+"_"+document.getElementById("FBSSSM").value+"_"+document.getElementById("TSBES").value+"_"+document.getElementById("TSBEM").value+"_"+document.getElementById("FBEFSS").value+"_"+document.getElementById("FBEFSM").value+"_"+document.getElementById("FBESSS").value+"_"+document.getElementById("FBESSM").value+"_"+document.getElementById("TSES").value+"_"+document.getElementById("TSEM").value+"_"+document.getElementById("SBEFSS").value+"_"+document.getElementById("SBEFSM").value+"_"+document.getElementById("EHSES").value+"_"+document.getElementById("EHSEM").value+"_"+document.getElementById("ALARMS").value+"_");
        xhttp.send(); 
      }
                function shift() {
        var xhttp = new XMLHttpRequest();
xhttp.open("GET", "setText?TextContents="+"y_"+document.getElementById("FYN").value+"_"+document.getElementById("SYN").value+"_"+document.getElementById("TYN").value+"_"+document.getElementById("12H").value+"_");
        xhttp.send(); 
      }
                    function temp() {
        var xhttp = new XMLHttpRequest();
xhttp.open("GET", "setText?TextContents="+"p_"+document.getElementById("TEMPM").value+"_"+document.getElementById("TEMPP").value+"_");
        xhttp.send(); 
      }
    </script>
  </body>
</html>
)=====";

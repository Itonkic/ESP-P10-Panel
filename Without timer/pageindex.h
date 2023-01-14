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
    <button type="button" class="button1" onclick="test()">Test</button>
      <h3>LED Matrix</h3>
    <label align="left" for="FSS">Scrolling text: </label>
    <input align="left" type="text" id="SRD" name="Srednji red" size = "30" placeholder=" ">
    <br>
    <br>
    </div>
  <table style="margin-left:auto;margin-right:auto;">
  </table>
  
    <div>
    <button type="button" class="buttonSend" onclick="send()">Update texta</button>
    </div>
  <table>
<tbody>
     <tr>
        <td><label for="dog-names"></label>&nbsp;</td>
     </tr>

    </tbody>
  </table>
    <script>
        function send() {
        var xhttp = new XMLHttpRequest();
        xhttp.open("GET", "setText?TextContents="+"t_"+document.getElementById("SRD").value);
        xhttp.send(); 
      }

    </script>
  </body>
</html>
)=====";

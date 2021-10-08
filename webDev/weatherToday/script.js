
var city = "Ghaziabad"

$.getJSON("https://api.openweathermap.org/data/2.5/weather?q=Ghaziabad,%20IN&units=metric&APPID=fa8692e029844657d2a0595392c02a00", function(data) {
    console.log(data);

    var icon="https://openweathermap.org/img/wn/" + data.weather[0].icon + ".png";
    var temp = Math.floor(data.main.temp) + " °C";
    var weather = data.weather[0].main;
    var location = data.name + ", " + data.sys.country;

    $(".location").append(location);
    $(".icon").attr("src", icon);
    $(".weather").append(weather);
    $(".temp").append(temp);
});
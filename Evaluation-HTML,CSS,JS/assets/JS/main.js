// ===========  GLOBAL ============ //
var response;
var appartmentCount = 0;
var houseCount = 0;
var restaurantCount = 0;
var storeCount = 0;
var villaCount = 0;
var spaCount = 0;

// -----------  NEWS AND STORIES JSON ------------ //
var newsData = [
	{
		newsImage: "assets/img/news-img-001.jpg",
		newsTitle: "Independent apartment with mordern design",
		newsAuthor: "Admin",
		newsDate: "JANUARY 16, 2018"
	},
	{
		newsImage: "assets/img/news-img-002.jpg",
		newsTitle: "Mordern apartment adjacent to eco park",
		newsAuthor: "Admin",
		newsDate: "JANUARY 16, 2018"
	},
	{
		newsImage: "assets/img/news-img-003.jpg",
		newsTitle: "We're doing business with pleasure",
		newsAuthor: "Admin",
		newsDate: "JANUARY 16, 2018"
	}
];
$.ajax({
	url: "/assets/json/propertyData.json",
	dataType: "json",
	success: function(data) {
		response = data;
	},
	error: function(errorThrown) {
		alert(errorThrown);
	}
});

function countAll() {
	for (each in propertyData) {
		console.log(propertyData[each]);
		for (type in propertyData[each].propertyType) {
			console.log(propertyData[each].propertyType[type]);
			console.log(propertyData[each].propertyType[type]);
			if (propertyData[each].propertyType[type] == "APARTMENT") {
				appartmentCount++;
				console.log(appartmentCount,"hey");
			}
			if (propertyData[each].propertyType[type] == "HOUSE") {
				houseCount++;
			}
			if (propertyData[each].propertyType[type] == "RESTAURANT") {
				restaurantCount++;
			}
			if (propertyData[each].propertyType[type] == "STORE") {
				storeCount++;
			}
			if (propertyData[each].propertyType[type] == "VILLA") {
				villaCount++;
			}
			if (propertyData[each].propertyType[type] == "SPA") {
				spaCount++;
			}
		}
	}
}

// ===========  DOCUMENT READY ============ //
$(function() {
	$("#footer").load("footer.html");
	$(".navbar-rest").load("./navbar.html #loadPoint");
	$(".categories").append(
		' <div class="overlay"><a href class="line-title">View All<div class="fill-line"></div></a></div> '
	);
	$(".cat-title").append('<p class=" cat-subtitle add-opacity">Hello</p> ');
	newsDisplay();

	function newsDisplay() {
		for (data in newsData) {
			var newImage =
				'<img class="padding-img image" src="' +
				newsData[data].newsImage +
				'" width="300px" height="300px">';
			var newTitle =
				'<a href="./error.html"><h4 class="news-title">' +
				newsData[data].newsTitle +
				"</h4></a>";
			var newCaption =
				"<p> BY&nbsp<label>" +
				newsData[data].newsAuthor +
				"</label>&nbsp&nbsp|&nbsp&nbsp" +
				newsData[data].newsDate +
				"</p>";
			var newContent =
				'<div class="col-4 p-2 each-news">' +
				newImage +
				newCaption +
				newTitle +
				"</div>";
			$("#news-content").append(newContent);
		}
	}
	propertyData = response.Data[0];
	console.log(propertyData);
	countAll();
	console.log(appartmentCount);
});

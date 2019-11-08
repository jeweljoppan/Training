// ===========  GLOBAL ============ //
var lastActive = "list";

//JSON object for property data

$("#navbar").load("navbar.html #loadPoint");
$("#footer").load("footer.html");
function getData() {
	$.ajax({
		url: "/assets/json/propertyData.json",
		dataType: "json",
		success: function(data) {
			var propertyData = Data.Data;
			alert("propertyData");
			displayAll(propertyData);
		},
		error: function(errorThrown) {
			alert(errorThrown);
		}
	});
}

function displayAll(propertyData) {
	$(".content").html("");
	console.log(propertyData);
	for (data in propertyData) {
		display(propertyData[data]);
	}
}
function display(propertyData) {
	var propImage =
		'<img class="col-4 padding-img image" src="' +
		propertyData.propertyImage +
		'" width="250px" height="250px">';
	var propType = '<div class="type">';
	for (type in propertyData.propertyType) {
		propType +=
			'<label class="list-subtitle">' +
			propertyData.propertyType[type] +
			"&nbsp</label>";
	}
	propType += "</div>";
	var propTitle =
		'<a href="./error.html"><h4 class="list-title title">' +
		propertyData.propertyName +
		"</h4></a>";
	var propAddress =
		'<p class="list-text address">' +
		propertyData.propertyAddress[0] +
		", " +
		propertyData.propertyAddress[1] +
		", " +
		propertyData.propertyAddress[2] +
		", " +
		propertyData.propertyAddress[3] +
		"</p>";
	var propDesc =
		'<p class="list-text desc">' + propertyData.propertyDescription + "</p>";
	var propNeed =
		'<label class="col-6 list-green">FOR&nbsp' +
		propertyData.propertyNeed[0] +
		"</label>";
	var propPrice =
		'<label class="col-6 list-black">$' +
		propertyData.propertyPrice +
		"</label>";
	var content =
		'<div class="prop-object list-width row">' +
		propImage +
		'<div class="col-8 padding-content">' +
		propType +
		propTitle +
		propAddress +
		propDesc +
		'<div class="pt-lg-5">' +
		propNeed +
		propPrice +
		"</div></div></div>";
	$(".content").append(content);
}

$(".view").on("click", clickRegister);
function clickRegister() {
	if ($(this).hasClass("grid")) {
		lastActive = "grid";
	}
	if ($(this).hasClass("list")) {
		lastActive = "list";
	}
	view();
}
function view() {
	if (lastActive == "grid") {
		$(".content")
			.removeClass("flex-column")
			.addClass("flex-row")
			.addClass("flex-wrap");
		$(".content .prop-object")
			.removeClass("list-width")
			.addClass("grid-width");
		$(".title").addClass("condense");
		$(".desc")
			.removeClass("d-inline-block")
			.addClass("d-none");
		$(".address").addClass("condense");
		$(".image")
			.removeClass("col-4")
			.addClass("col-12");
		$(".padding-content")
			.removeClass("col-8")
			.addClass("col-12");
	} else if (lastActive == "list") {
		$(".content")
			.removeClass("flex-row")
			.addClass("flex-column");
		$(".content .prop-object")
			.addClass("list-width")
			.removeClass("grid-width");
		$(".image")
			.removeClass("col-12")
			.addClass("col-4");
		$(".title").removeClass("condense");
		$(".desc").addClass("d-inline-block");
		$(".address").removeClass("condense");
		$(".padding-content")
			.addClass("col-8")
			.removeClass("col-12");
	}
}

$(".filter").on("click", function() {
	if ($(this).hasClass("rent")) {
		$(".content").empty();
		for (data in propertyData) {
			if (propertyData[data].propertyNeed[0] == "RENT") {
				display(propertyData[data]);
			}
		}
	}
	if ($(this).hasClass("sale")) {
		$(".content").empty();
		for (data in propertyData) {
			if (propertyData[data].propertyNeed[0] == "SALE") {
				display(propertyData[data]);
			}
		}
	}
	view();
});
$(".search").on("click", function() {
	var flag = 0;
	var label = $("#label-search").val();
	if (label == "All Labels") {
		displayAll();
	} else {
		label += ",";
		$(".content").empty();
		for (data in propertyData) {
			flag = 0;
			for (each in propertyData[data].propertyType) {
				if (
					label.toUpperCase() == propertyData[data].propertyType[each] &&
					flag == 0
				) {
					display(propertyData[data]);
					flag = 1;
				}
			}
		}
	}
	view();
});
$("#slider-range").slider({
	range: true,
	min: 1000,
	max: 1000000,
	values: [15000, 100000],
	slide: function(event, ui) {
		$("#amount").val("$" + ui.values[0] + " - $" + ui.values[1]);
	}
});
$("#amount").val(
	"$" +
		$("#slider-range").slider("values", 0) +
		" - $" +
		$("#slider-range").slider("values", 1)
);
$(".ui-slider-handle").addClass("handle-icon");
$(".ui-slider-range").addClass("range-color");
$(".ui-slider").addClass("slider-height");

// ===========  DOCUMENT READY ============ //
$(document).ready(function() {
	getData();
});

// ===========  DOCUMENT READY ============ //
$(function() {
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
});

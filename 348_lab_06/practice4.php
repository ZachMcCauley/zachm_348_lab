<?php
	if ($_SERVER["REQUEST_METHOD"] == "POST") {
		$size = intval($_POST["size"]);
		if ($size > 0) {
			print "<h2>Multiplication Table of size $size</h2>";
			print "<table border='1' cellpadding='5' cellspacing='0'>";

			print "<tr<td></td>";
			for ($i = 1; $i <= $size; $i++) {
				print "<td><strong>$i</strong></td>";
			}
			print "</tr>";

			for ($i = 1; $i <= $size; $i++) {
				print "<tr>";
				print "<td><strong>$i</strong></td>";
				for ($j = 1; $j <= $size; $j++) {
					print "<td>" . ($i * $j) . "</td>";
				}
				print "</tr>";
			}
			print "</table>";
		} else {
			print "Please enter a valid positive number.";
		}
	}
?>

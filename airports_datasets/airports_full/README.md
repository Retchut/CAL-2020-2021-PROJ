# Airports dataset

This dataset is a directed graph with 3425 airports (nodes) and 37595 routes (edges).

- [airports_full_nodes_latlng.txt](node_coords.txt): List of all nodes and their coordinates (latitude and longitude)
- [airports_full_nodes_names.txt](node_names.txt): List of all nodes and their IATA codes (may be useful to visualize)
- [airports_full_edges.txt](edges.txt): List of all edges
- [airports_full_edges_weights.txt](edge_weights.txt) List of all edges, and their weights

## Sources

| File                                      | Source                                                                            |
|-------------------------------------------|-----------------------------------------------------------------------------------|
| [`routes.csv`](routes.csv)                | [Openflights - Routes](https://openflights.org/data.html)                         |
| [`airport-codes.csv`](airport-codes.csv)  | [Datahub - airport codes](https://datahub.io/core/airport-codes#data)             |
| [`airports1.csv`](airports1.csv)          | [Openflights - Airports](https://openflights.org/data.html)                       |
| [`airports2.csv`](airports2.csv)          | [OurAirports](https://ourairports.com/data/)                                      |
| [`airports3.csv`](airports3.csv)          | Mostly from [TravelMath](https://www.travelmath.com/airport/)                     |

## Distance between two coordinates in a globe

Although we provide a file with all edge weights (airports_full_edges_weights.txt), you may still want to know how to calculate the distance between two points in the globe (e.g., if you're designing an heuristic for the A* algorithm you might need to determine distances).

Here is the C++ code that applies the [haversine formula](https://www.movable-type.co.uk/scripts/latlong.html) to calculate the distance in meters between two points for which we know their latitudes and longitudes (in degree).

```c++
const double PI = atan(1)*4;

double distance(double lat1, double lon1, double lat2, double lon2){
    // Earth's radius is 6371000m on average.
    // Planes fly at an average altitude of 35000 ft, or about 10700m.
    const double R = 6371000 + 10700;
    double phi1 = lat1 * PI/180;
    double phi2 = lat2 * PI/180;
    double deltaPhi = (lat2-lat1) * PI/180;
    double deltaLambda = (lon2-lon1) * PI/180;

    double a =
            sin(deltaPhi/2.0) * sin(deltaPhi/2.0) +
            cos(phi1) * cos(phi2) *
            sin(deltaLambda/2.0) * sin(deltaLambda/2.0);
    double c = 2.0 * atan2(sqrt(a), sqrt(1-a));

    double d = R * c;

    return d;
}
```

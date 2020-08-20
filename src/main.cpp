// Author(s) : Camille Wormser, Pierre Alliez

#include <iostream>
#include <fstream>
#include <list>
#include <vector>

#include <CGAL/Simple_cartesian.h>
#include <CGAL/Surface_mesh.h>
#include <CGAL/AABB_tree.h>
#include <CGAL/AABB_traits.h>
#include <CGAL/AABB_triangle_primitive.h>
#include <CGAL/AABB_face_graph_triangle_primitive.h>

typedef CGAL::Simple_cartesian<double> K;

typedef K::FT FT;
typedef K::Ray_3 Ray;
typedef K::Line_3 Line;
typedef K::Point_3 Point;
typedef K::Triangle_3 Triangle;

typedef CGAL::Surface_mesh<Point> Mesh;

typedef std::list<Triangle>::iterator Iterator;
// typedef CGAL::AABB_triangle_primitive<K, Iterator> Primitive;
// typedef CGAL::AABB_traits<K, Primitive> AABB_triangle_traits;
// typedef CGAL::AABB_tree<AABB_triangle_traits> Tree;
typedef CGAL::AABB_face_graph_triangle_primitive<Mesh> Primitive;
typedef CGAL::AABB_traits<K, Primitive> Traits;
typedef CGAL::AABB_tree<Traits> Tree;

/////

#include <CGAL/AABB_face_graph_triangle_primitive.h>

// typedef CGAL::AABB_face_graph_triangle_primitive<Mesh> Primitive;

int main(int argc, char* argv[])
{
    Point a(1.0, 0.0, 0.0);
    Point b(0.0, 1.0, 0.0);
    Point c(0.0, 0.0, 1.0);
    Point d(0.0, 0.0, 0.0);
    Point e(0.0, 0.0, -100);
    Point f(0.0, 1.0, 0);

    const char* filename = (argc > 1) ? argv[1] : "data/tetrahedron.off";
    std::ifstream input(filename);
    Mesh mesh;
    input >> mesh;
    Tree tree(faces(mesh).first, faces(mesh).second, mesh);
    // std::list<Triangle> triangles;
    // triangles.push_back(Triangle(a,b,c));
    // triangles.push_back(Triangle(a,b,d));
    // triangles.push_back(Triangle(a,d,c));

    // constructs AABB tree
    // Tree tree(triangles.begin(),triangles.end());

    // counts #intersections
    Ray ray_query(e,f);
    std::cout << tree.number_of_intersected_primitives(ray_query)
        << " intersections(s) with ray query" << std::endl;

    // compute closest point and squared distance
    // Point point_query(2.0, 2.0, 2.0);
    // Point closest_point = tree.closest_point(point_query);
    // std::cerr << "closest point is: " << closest_point << std::endl;
    // FT sqd = tree.squared_distance(point_query);
    // std::cout << "squared distance: " << sqd << std::endl;

    return EXIT_SUCCESS;
}

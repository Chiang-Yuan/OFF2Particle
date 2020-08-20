/*
STL2Particle

Yuan Chiang (20th/Aug/2020)

Adapted from CGAL 5.0.3 example - AABB Tree
Author(s) : Camille Wormser, Pierre Alliez
*/

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
typedef CGAL::AABB_face_graph_triangle_primitive<Mesh> Primitive;
typedef CGAL::AABB_traits<K, Primitive> Traits;
typedef CGAL::AABB_tree<Traits> Tree;

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

    Ray ray_query(e,f);
    std::cout << tree.number_of_intersected_primitives(ray_query)
        << " intersections(s) with ray query" << std::endl;

    return EXIT_SUCCESS;
}

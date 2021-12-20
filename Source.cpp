// Include standard headers
#include <stdio.h>
#include <stdlib.h>

// Include GLEW
#include <gl/glew.h>
#include <glm/gtc/type_ptr.hpp>
#include "glm/gtc/matrix_transform.hpp"

// Include GLFW
#include <GLFW/glfw3.h>
GLFWwindow* window;

// Include GLM
#include <glm/glm.hpp>
#include <iostream>
#define triangles 4096
using namespace std;
using namespace glm;

GLfloat vertexPositions[100000];
GLfloat normals[100000];

GLfloat Point1[3] = { 0.0f, 1.0f, 0.0f };
GLfloat Point2[3] = { -0.5f, 0.0f, 0.0f };
GLfloat Point3[3] = { 0.5f, 0.0f, 0.0f };
GLfloat Point4[3] = { 0.0f,  0.0f, -0.5f };

GLfloat Point5[3] = { -1.0f, 1.0f, -1.0f };
GLfloat Point6[3] = { -0.5f, 2.0f, -1.0f };
GLfloat Point7[3] = { -1.5f, 2.0f, -1.0f };
GLfloat Point8[3] = { -1.0f,  2.0f, -1.5f };

GLfloat Point9[3] = { 0.0f, 0.5f, 0.0f };
GLfloat Point10[3] = { -0.5f, -0.5f, 0.25f };
GLfloat Point11[3] = { 0.5f, -0.5f, 0.25f };
GLfloat Point12[3] = { 0.0f,  -0.5f, -0.25f };

GLfloat SquarePoint1[3] = { 1.5f, 0.0f, 0.0f };
GLfloat SquarePoint2[3] = { 1.5f, 1.0f, 0.0f };
GLfloat SquarePoint3[3] = { 2.5f,  1.0f, 0.0f };
GLfloat SquarePoint4[3] = { 2.5f, 0.0f, 0.0f };
GLfloat SquarePoint5[3] = { 1.5f, 0.0f, -1.0f };
GLfloat SquarePoint6[3] = { 1.5f, 1.0f, -1.0f };
GLfloat SquarePoint7[3] = { 2.5f,  1.0f, -1.0f };
GLfloat SquarePoint8[3] = { 2.5f, 0.0f, -1.0f };

GLfloat SmallSquarePoint1[3] = { -1.5f, 0.0f, 0.0f };
GLfloat SmallSquarePoint2[3] = { -1.5f, 0.5f, 0.0f };
GLfloat SmallSquarePoint3[3] = { -1.0f,  0.5f, 0.0f };
GLfloat SmallSquarePoint4[3] = { -1.0f, 0.0f, 0.0f };
GLfloat SmallSquarePoint5[3] = { -1.5f, 0.0f, -0.5f };
GLfloat SmallSquarePoint6[3] = { -1.5f, 0.5f, -0.5f };
GLfloat SmallSquarePoint7[3] = { -1.0f,  0.5f, -0.5f };
GLfloat SmallSquarePoint8[3] = { -1.0f, 0.0f, -0.5f };

GLfloat SpongeSquarePoint1[3] = { -0.5f, 0.0f, 0.0f };
GLfloat SpongeSquarePoint2[3] = { -0.5f, 1.0f, 0.0f };
GLfloat SpongeSquarePoint3[3] = { 0.5f,  1.0f, 0.0f };
GLfloat SpongeSquarePoint4[3] = { 0.5f, 0.0f, 0.0f };
GLfloat SpongeSquarePoint5[3] = { -0.5f, 0.0f, -1.0f };
GLfloat SpongeSquarePoint6[3] = { -0.5f, 1.0f, -1.0f };
GLfloat SpongeSquarePoint7[3] = { 0.5f,  1.0f, -1.0f };
GLfloat SpongeSquarePoint8[3] = { 0.5f, 0.0f, -1.0f };

GLfloat RectanglePoint1[3] = { 0.0f, 1.1f, 0.0f };
GLfloat RectanglePoint2[3] = { 0.0f, 2.1f, 0.0f };
GLfloat RectanglePoint3[3] = { 2.5f, 2.1f, 0.0f };
GLfloat RectanglePoint4[3] = { 2.5f, 1.1f, 0.0f };
GLfloat RectanglePoint5[3] = { 0.0f, 1.1f, -1.0f };
GLfloat RectanglePoint6[3] = { 0.0f, 2.1f, -1.0f };
GLfloat RectanglePoint7[3] = { 2.5f, 2.1f, -1.0f };
GLfloat RectanglePoint8[3] = { 2.5f, 1.1f, -1.0f };

GLfloat vertexColors[] = {
		 1.0, 1.0, 0.0,
		 1.0, 1.0, 0.0,
		 1.0, 1.0, 0.0,
		 1.0, 1.0, 0.0,
		 1.0, 1.0, 0.0,
		 1.0, 1.0, 0.0,
		 1.0, 1.0, 0.0,
		 1.0, 1.0, 0.0,
		 1.0, 1.0, 0.0,
		 1.0, 1.0, 0.0,
		 1.0, 1.0, 0.0,
		 1.0, 1.0, 0.0,
		 1.0, 1.0, 0.0,
		 1.0, 1.0, 0.0,
		 1.0, 1.0, 0.0,
		 1.0, 1.0, 0.0,
		 1.0, 1.0, 0.0,
		 1.0, 1.0, 0.0,
		 1.0, 1.0, 0.0,
		 1.0, 1.0, 0.0,
		 1.0, 1.0, 0.0,
		 1.0, 1.0, 0.0,
		 1.0, 1.0, 0.0,
		 1.0, 1.0, 0.0,
		 1.0, 1.0, 0.0,
		 1.0, 1.0, 0.0,
		 1.0, 1.0, 0.0,
		 1.0, 1.0, 0.0,
		 1.0, 1.0, 0.0,
		 1.0, 1.0, 0.0,
		 1.0, 1.0, 0.0,
		 1.0, 1.0, 0.0,
		 1.0, 1.0, 0.0,
		 1.0, 1.0, 0.0,
		 1.0, 1.0, 0.0,
		 1.0, 1.0, 0.0,
		 1.0, 0.0, 0.0,
		 1.0, 0.0, 0.0,
		 1.0, 0.0, 0.0,
		 1.0, 0.0, 0.0,
		 1.0, 0.0, 0.0,
		 1.0, 0.0, 0.0,
		 1.0, 0.0, 0.0,
		 1.0, 0.0, 0.0,
		 1.0, 0.0, 0.0,
		 1.0, 0.0, 0.0,
		 1.0, 0.0, 0.0,
		 1.0, 0.0, 0.0,
		 1.0, 0.0, 0.0,
		 1.0, 0.0, 0.0,
		 1.0, 0.0, 0.0,
		 1.0, 0.0, 0.0,
		 1.0, 0.0, 0.0,
		 1.0, 0.0, 0.0,
		 1.0, 0.0, 0.0,
		 1.0, 0.0, 0.0,
		 1.0, 0.0, 0.0,
		 1.0, 0.0, 0.0,
		 1.0, 0.0, 0.0,
		 1.0, 0.0, 0.0,
		 1.0, 0.0, 0.0,
		 1.0, 0.0, 0.0,
		 1.0, 0.0, 0.0,
		 1.0, 0.0, 0.0,
		 1.0, 0.0, 0.0,
		 1.0, 0.0, 0.0,
		 1.0, 0.0, 0.0,
		 1.0, 0.0, 0.0,
		 1.0, 0.0, 0.0,
		 1.0, 0.0, 0.0,
		 1.0, 0.0, 0.0,
		 1.0, 0.0, 0.0,
		 0.0, 0.0, 1.0,
		 0.0, 0.0, 1.0,
		 0.0, 0.0, 1.0,
		 0.0, 0.0, 1.0,
		 0.0, 0.0, 1.0,
		 0.0, 0.0, 1.0,
		 0.0, 0.0, 1.0,
		 0.0, 0.0, 1.0,
		 0.0, 0.0, 1.0,
		 0.0, 0.0, 1.0,
		 0.0, 0.0, 1.0,
		 0.0, 0.0, 1.0,
		 1.0, 0.6, 0.0,
		 1.0, 0.6, 0.0,
		 1.0, 0.6, 0.0,
		 1.0, 0.6, 0.0,
		 1.0, 0.6, 0.0,
		 1.0, 0.6, 0.0,
		 1.0, 0.6, 0.0,
		 1.0, 0.6, 0.0,
		 1.0, 0.6, 0.0,
		 1.0, 0.6, 0.0,
		 1.0, 0.6, 0.0,
		 1.0, 0.6, 0.0,
		 1.0, 0.0, 0.0,
		 0.0, 1.0, 0.0,
		 0.0, 0.0, 1.0,
		 1.0, 0.0, 0.0,
		 0.0, 1.0, 0.0,
		 0.0, 0.0, 1.0,
		 1.0, 0.0, 0.0,
		 0.0, 1.0, 0.0,
		 0.0, 0.0, 1.0,
		 1.0, 0.0, 0.0,
		 0.0, 1.0, 0.0,
		 0.0, 0.0, 1.0,
		 1.0, 0.0, 0.0,
		 0.0, 1.0, 0.0,
		 0.0, 0.0, 1.0,
		 1.0, 0.0, 0.0,
		 0.0, 1.0, 0.0,
		 0.0, 0.0, 1.0,
		 1.0, 0.0, 0.0,
		 0.0, 1.0, 0.0,
		 0.0, 0.0, 1.0,
		 1.0, 0.0, 0.0,
		 0.0, 1.0, 0.0,
		 0.0, 0.0, 1.0,
		 1.0, 0.0, 0.0,
		 0.0, 1.0, 0.0,
		 0.0, 0.0, 1.0,
		 1.0, 0.0, 0.0,
		 0.0, 1.0, 0.0,
		 0.0, 0.0, 1.0,
		 1.0, 0.0, 0.0,
		 0.0, 1.0, 0.0,
		 0.0, 0.0, 1.0,
		 1.0, 0.0, 0.0,
		 0.0, 1.0, 0.0,
		 0.0, 0.0, 1.0
};

int numVertices = 3, index = 0, counter = 0, normIndex = 0, colorIndex = 0, triangleCount = 0, objectCount = 0;
int objectIndicies[20];
float angleRotate = 0;
GLuint shaderProgram, VAO, vertexBuffer, colorBuffer, normalBuffer, shaderGourProgram;
GLint MVPUniformLocation, objectWorldUniformLocation, lightPosUniformLocation, lightColorUniformLocation, lightPropUniformLocation;
GLint viewUniformLocation, projectionUniformLocation, typeUniformLocation, viewPosUniformLocation, ambientMaterialUniform, diffuseMaterialUniform, specularMaterialUniform, shininessMaterialUniform;
GLfloat transitionAmount = 0;
GLfloat interestX = 0.0f, interestY = 0.3f, interestZ = 0.0f;
GLfloat cameraLocationX = 0.5f, cameraLocationY = -0.5f, cameraLocationZ = 1.5f;
GLfloat cameraUpX = 0.3f, cameraUpY = 1.0f, cameraUpZ = 0.0f;
bool wireFlag = false, cond = false, rotateFlag = true, ambientFlag = true, diffuseFlag = true, specularFlag = true, phongFlag = true;
bool xRotateFlag = true, yRotateFlag = true, zRotateFlag = true;
string shaderChoice = "orange", currentfractal = "triangle";
vec3 lightPos = vec3(0.0f, 15.0f, 300.0f);
vec3 lightColor = vec3(1.0f, 1.0f, 1.0f);
vec3 rotateVec = vec3(0.0f, 1.0f, 0.0f);

void vertexNormal(GLfloat* A)
{
	for (int i = 0; i < 9; i += 1)
	{
		normals[normIndex + i] = A[i];
	}
	normIndex += 9;
}

void addToArray(GLfloat* shape, int vertexCount)
{
	vertexNormal(shape);
	vec3 normalizedPoint1 = normalize(vec3(shape[0], shape[1], shape[2]));
	vec3 normalizedPoint2 = normalize(vec3(shape[3], shape[4], shape[5]));
	vec3 normalizedPoint3 = normalize(vec3(shape[6], shape[7], shape[8]));
	for (int i = 0; i < 3; i++)
	{
		vertexPositions[index + i] = normalizedPoint1[i];
	}
	for (int i = 0; i < 3; i++)
	{
		vertexPositions[index + i + 3] = normalizedPoint2[i];
	}
	for (int i = 0; i < 3; i++)
	{
		vertexPositions[index + i + 6] = normalizedPoint3[i];
	}
	index += vertexCount * 3;

}

GLfloat* midPoint(GLfloat* A, GLfloat* B)
{
	GLfloat* C = (GLfloat*)malloc(sizeof(GLfloat) * 3);
	for (int i = 0; i < 3; i++)
	{
		C[i] = (A[i] + B[i]) / 2;
	}
	return C;
}

void calculateTriangleNormal(GLfloat* A, GLfloat* B, GLfloat* C)
{
	vec3 vecA = vec3(A[0], A[1], A[2]);
	vec3 vecB = vec3(B[0], B[1], B[2]);
	vec3 vecC = vec3(C[0], C[1], C[2]);
	vec3 edge1, edge2, normal;

	edge1 = vecB - vecA;
	edge2 = vecC - vecA;
	normal = normalize(cross(edge1, edge2));
	for (int i = 0; i < 9; i += 3)
	{
		normals[normIndex + i] = normal[0];
		normals[normIndex + i + 1] = normal[1];
		normals[normIndex + i + 2] = normal[2];
	}
	normIndex += 9;
}

void calculateSquareNormal(GLfloat* A, GLfloat* B, GLfloat* C)
{
	vec3 vecA = vec3(A[0], A[1], A[2]);
	vec3 vecB = vec3(B[0], B[1], B[2]);
	vec3 vecC = vec3(C[0], C[1], C[2]);
	vec3 edge1, edge2, normal;

	edge1 = vecB - vecA;
	edge2 = vecC - vecA;
	normal = normalize(cross(edge1, edge2));
	for (int i = 0; i < 18; i += 3)
	{
		normals[normIndex + i] = normal[0];
		normals[normIndex + i + 1] = normal[1];
		normals[normIndex + i + 2] = normal[2];
	}
	normIndex += 18;
}

GLfloat* oneThirdPoint(GLfloat* A, GLfloat* B)
{
	GLfloat* C = (GLfloat*)malloc(sizeof(GLfloat) * 3);
	for (int i = 0; i < 3; i++)
	{
		C[i] = A[i] + ((B[i] - A[i]) / 3);
	}
	return C;
}

GLfloat* triangle(GLfloat* A, GLfloat* B, GLfloat* C, bool sphereFlag)
{
	if (!sphereFlag)
	{
		calculateTriangleNormal(A, B, C);
	}

	GLfloat* triangle = (GLfloat*)malloc(sizeof(GLfloat) * 9);
	triangle[0] = A[0];
	triangle[1] = A[1];
	triangle[2] = A[2];
	triangle[3] = B[0];
	triangle[4] = B[1];
	triangle[5] = B[2];
	triangle[6] = C[0];
	triangle[7] = C[1];
	triangle[8] = C[2];
	triangleCount++;
	return triangle;
}

GLfloat* square(GLfloat* A, GLfloat* B, GLfloat* C, GLfloat* D)
{
	calculateTriangleNormal(A, D, B);
	calculateTriangleNormal(C, B, D);
	GLfloat* square = (GLfloat*)malloc(sizeof(GLfloat) * 18);
	square[0] = A[0];
	square[1] = A[1];
	square[2] = A[2];
	square[3] = B[0];
	square[4] = B[1];
	square[5] = B[2];
	square[6] = D[0];
	square[7] = D[1];
	square[8] = D[2];
	square[9] = C[0];
	square[10] = C[1];
	square[11] = C[2];
	square[12] = B[0];
	square[13] = B[1];
	square[14] = B[2];
	square[15] = D[0];
	square[16] = D[1];
	square[17] = D[2];
	triangleCount++;
	triangleCount++;
	return square;
}

void cube(GLfloat* A, GLfloat* B, GLfloat* C, GLfloat* D, GLfloat* E, GLfloat* F, GLfloat* G, GLfloat* H)
{
	int switchCase = -1;

	GLfloat* square1 = square(A, B, C, D);
	GLfloat* square2 = square(E, H, G, F);
	GLfloat* square3 = square(F, B, A, E);
	GLfloat* square4 = square(A, D, H, E);
	GLfloat* square5 = square(D, C, G, H);
	GLfloat* square6 = square(B, F, G, C);
	for (int i = 0; i < 18 * 6; i++)
	{
		if (i % 18 == 0)switchCase++;
		switch (switchCase)
		{
		case 0:
			vertexPositions[index + i] = square1[i];
			break;
		case 1:
			vertexPositions[index + i] = square2[i - 18];
			break;
		case 2:
			vertexPositions[index + i] = square3[i - 36];
			break;
		case 3:
			vertexPositions[index + i] = square4[i - 54];
			break;
		case 4:
			vertexPositions[index + i] = square5[i - 72];
			break;
		case 5:
			vertexPositions[index + i] = square6[i - 90];
			break;
		}
	}
	free(square1);
	free(square2);
	free(square3);
	free(square4);
	free(square5);
	free(square6);
	index += (18 * 6);
}

void tetra(GLfloat* A, GLfloat* B, GLfloat* C, GLfloat* D)
{
	int switchCase = -1;

	GLfloat* triangle1 = triangle(A, B, C, false);
	GLfloat* triangle2 = triangle(A, D, B, false);
	GLfloat* triangle3 = triangle(A, C, D, false);
	GLfloat* triangle4 = triangle(D, C, B, false);
	for (int i = 0; i < 9 * 4; i++)
	{
		if (i % 9 == 0)switchCase++;
		switch (switchCase)
		{
		case 0:
			vertexPositions[index + i] = triangle1[i];
			break;
		case 1:
			vertexPositions[index + i] = triangle2[i - 9];
			break;
		case 2:
			vertexPositions[index + i] = triangle3[i - 18];
			break;
		case 3:
			vertexPositions[index + i] = triangle4[i - 27];
			break;
		}
	}
	free(triangle1);
	free(triangle2);
	free(triangle3);
	free(triangle4);
	index += (9 * 4);
}

void Sponge(GLfloat* A, GLfloat* B, GLfloat* C, GLfloat* D, GLfloat* E, GLfloat* F, GLfloat* G, GLfloat* H, int depth)
{
	if (depth < 0)
	{
		return;
	}

	if (depth == 0)
	{
		cube(A, B, C, D, E, F, G, H);
	}

	Sponge(A, oneThirdPoint(A, B), oneThirdPoint(A, C), oneThirdPoint(A, D), oneThirdPoint(A, E), oneThirdPoint(A, F), oneThirdPoint(A, G), oneThirdPoint(A, H), depth - 1);
	Sponge(oneThirdPoint(B, A), B, oneThirdPoint(B, C), oneThirdPoint(B, D), oneThirdPoint(B, E), oneThirdPoint(B, F), oneThirdPoint(B, G), oneThirdPoint(B, H), depth - 1);
	Sponge(oneThirdPoint(C, A), oneThirdPoint(C, B), C, oneThirdPoint(C, D), oneThirdPoint(C, E), oneThirdPoint(C, F), oneThirdPoint(C, G), oneThirdPoint(C, H), depth - 1);
	Sponge(oneThirdPoint(D, A), oneThirdPoint(D, B), oneThirdPoint(D, C), D, oneThirdPoint(D, E), oneThirdPoint(D, F), oneThirdPoint(D, G), oneThirdPoint(D, H), depth - 1);
	Sponge(oneThirdPoint(E, A), oneThirdPoint(E, B), oneThirdPoint(E, C), oneThirdPoint(E, D), E, oneThirdPoint(E, F), oneThirdPoint(E, G), oneThirdPoint(E, H), depth - 1);
	Sponge(oneThirdPoint(F, A), oneThirdPoint(F, B), oneThirdPoint(F, C), oneThirdPoint(F, D), oneThirdPoint(F, E), F, oneThirdPoint(F, G), oneThirdPoint(F, H), depth - 1);
	Sponge(oneThirdPoint(G, A), oneThirdPoint(G, B), oneThirdPoint(G, C), oneThirdPoint(G, D), oneThirdPoint(G, E), oneThirdPoint(G, F), G, oneThirdPoint(G, H), depth - 1);
	Sponge(oneThirdPoint(H, A), oneThirdPoint(H, B), oneThirdPoint(H, C), oneThirdPoint(H, D), oneThirdPoint(H, E), oneThirdPoint(H, F), oneThirdPoint(H, G), H, depth - 1);

	Sponge(oneThirdPoint(A, D), oneThirdPoint(A, C), oneThirdPoint(D, B), oneThirdPoint(D, A), oneThirdPoint(A, H), oneThirdPoint(A, G), oneThirdPoint(D, F), oneThirdPoint(D, E), depth - 1);
	Sponge(oneThirdPoint(A, B), oneThirdPoint(B, A), oneThirdPoint(B, D), oneThirdPoint(A, C), oneThirdPoint(A, F), oneThirdPoint(B, E), oneThirdPoint(B, H), oneThirdPoint(A, G), depth - 1);
	Sponge(oneThirdPoint(B, D), oneThirdPoint(B, C), oneThirdPoint(C, B), oneThirdPoint(C, A), oneThirdPoint(B, H), oneThirdPoint(B, G), oneThirdPoint(C, F), oneThirdPoint(C, E), depth - 1);
	Sponge(oneThirdPoint(D, B), oneThirdPoint(C, A), oneThirdPoint(C, D), oneThirdPoint(D, C), oneThirdPoint(D, F), oneThirdPoint(C, E), oneThirdPoint(C, H), oneThirdPoint(D, G), depth - 1);

	Sponge(oneThirdPoint(E, D), oneThirdPoint(E, C), oneThirdPoint(H, B), oneThirdPoint(H, A), oneThirdPoint(E, H), oneThirdPoint(E, G), oneThirdPoint(H, F), oneThirdPoint(H, E), depth - 1);
	Sponge(oneThirdPoint(F, D), oneThirdPoint(F, C), oneThirdPoint(G, B), oneThirdPoint(G, A), oneThirdPoint(F, H), oneThirdPoint(F, G), oneThirdPoint(G, F), oneThirdPoint(G, E), depth - 1);
	Sponge(oneThirdPoint(E, B), oneThirdPoint(F, A), oneThirdPoint(F, D), oneThirdPoint(E, C), oneThirdPoint(E, F), oneThirdPoint(F, E), oneThirdPoint(F, H), oneThirdPoint(E, G), depth - 1);
	Sponge(oneThirdPoint(H, B), oneThirdPoint(G, A), oneThirdPoint(G, D), oneThirdPoint(H, C), oneThirdPoint(H, F), oneThirdPoint(G, E), oneThirdPoint(G, H), oneThirdPoint(H, G), depth - 1);

	Sponge(oneThirdPoint(A, E), oneThirdPoint(A, F), oneThirdPoint(A, G), oneThirdPoint(A, H), oneThirdPoint(E, A), oneThirdPoint(E, B), oneThirdPoint(E, C), oneThirdPoint(E, D), depth - 1);
	Sponge(oneThirdPoint(B, E), oneThirdPoint(B, F), oneThirdPoint(B, G), oneThirdPoint(B, H), oneThirdPoint(F, A), oneThirdPoint(F, B), oneThirdPoint(F, C), oneThirdPoint(F, D), depth - 1);
	Sponge(oneThirdPoint(C, E), oneThirdPoint(C, F), oneThirdPoint(C, G), oneThirdPoint(C, H), oneThirdPoint(G, A), oneThirdPoint(G, B), oneThirdPoint(G, C), oneThirdPoint(G, D), depth - 1);
	Sponge(oneThirdPoint(D, E), oneThirdPoint(D, F), oneThirdPoint(D, G), oneThirdPoint(D, H), oneThirdPoint(H, A), oneThirdPoint(H, B), oneThirdPoint(H, C), oneThirdPoint(H, D), depth - 1);
}

void triangleFractal(GLfloat* A, GLfloat* B, GLfloat* C, GLfloat* D, int depth)
{
	if (depth < 0)
	{
		return;
	}

	if (depth == 0)
	{
		tetra(A, B, C, D);
		return;
	}
	triangleFractal(A, midPoint(A, B), midPoint(A, C), midPoint(A, D), depth - 1);
	triangleFractal(midPoint(B, A), B, midPoint(B, C), midPoint(B, D), depth - 1);
	triangleFractal(midPoint(C, A), midPoint(C, B), C, midPoint(C, D), depth - 1);
	triangleFractal(midPoint(D, A), midPoint(D, B), midPoint(D, C), D, depth - 1);
}

void curvedTetra(GLfloat* A, GLfloat* B, GLfloat* C, int depth)
{
	if (depth < 0)
	{
		return;
	}

	if (depth == 0)
	{
		addToArray(triangle(A, B, C, true), 3);
		return;
	}
	curvedTetra(A, midPoint(A, B), midPoint(A, C), depth - 1);
	curvedTetra(midPoint(B, A), B, midPoint(B, C), depth - 1);
	curvedTetra(midPoint(C, A), midPoint(C, B), C, depth - 1);
	curvedTetra(midPoint(C, A), midPoint(A, B), midPoint(B, C), depth - 1);
}

void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
	if (key == GLFW_KEY_1 && action == GLFW_PRESS)
	{
		shaderChoice = "orange", currentfractal = "triangle";
		triangleCount = 0, index = 0, normIndex = 0, counter = 0, objectCount = 0;
		fill_n(normals, 100000, 0);
		fill_n(vertexPositions, 100000, 0);
		triangleFractal(Point1, Point2, Point3, Point4, counter);
		objectIndicies[objectCount] = triangleCount;
		objectCount++;
		glBindBuffer(GL_ARRAY_BUFFER, vertexBuffer);
		glBufferData(GL_ARRAY_BUFFER, sizeof(vertexPositions), vertexPositions, GL_STATIC_DRAW);

		glBindBuffer(GL_ARRAY_BUFFER, normalBuffer);
		glBufferData(GL_ARRAY_BUFFER, sizeof(normals), normals, GL_STATIC_DRAW);

		interestX = 0.0f;
		interestY = 0.3f;
		interestZ = 0.0f;

		cameraLocationX = 0.5f;
		cameraLocationY = -0.5f;
		cameraLocationZ = 1.5f;

		cameraUpX = 0.3;
		cameraUpY = 1.0f;
		cameraUpZ = 0.0;

		angleRotate = 0;
	}
	if (key == GLFW_KEY_2 && action == GLFW_PRESS)
	{
		interestX = 0.0f;
		interestY = 0.5f;
		interestZ = -0.5f;

		cameraLocationX = 0.0f;
		cameraLocationY = 0.2f;
		cameraLocationZ = -0.2f;

		cameraUpX = 0.0;
		cameraUpY = 1.0f;
		cameraUpZ = 0.0;

		angleRotate = 0;
	}
	if (key == GLFW_KEY_3 && action == GLFW_PRESS)
	{
		shaderChoice = "orange", currentfractal = "sponge";
		triangleCount = 0, index = 0, normIndex = 0, counter = 0, objectCount = 0;
		fill_n(normals, 100000, 0);
		fill_n(vertexPositions, 100000, 0);
		Sponge(SpongeSquarePoint1, SpongeSquarePoint2, SpongeSquarePoint3, SpongeSquarePoint4, SpongeSquarePoint5, SpongeSquarePoint6, SpongeSquarePoint7, SpongeSquarePoint8, counter);
		objectIndicies[objectCount] = triangleCount;
		objectCount++;

		glBindBuffer(GL_ARRAY_BUFFER, vertexBuffer);
		glBufferData(GL_ARRAY_BUFFER, sizeof(vertexPositions), vertexPositions, GL_STATIC_DRAW);

		glBindBuffer(GL_ARRAY_BUFFER, normalBuffer);
		glBufferData(GL_ARRAY_BUFFER, sizeof(normals), normals, GL_STATIC_DRAW);

		interestX = 0.0f;
		interestY = 0.3f;
		interestZ = 0.0f;

		cameraLocationX = 0.5f;
		cameraLocationY = -0.5f;
		cameraLocationZ = 1.5f;

		cameraUpX = 0.0;
		cameraUpY = 1.0f;
		cameraUpZ = 0.0;

		angleRotate = 0;
	}
	if (key == GLFW_KEY_4 && action == GLFW_PRESS)
	{
		shaderChoice = "customColors", currentfractal = "none";
		triangleCount = 0, index = 0, normIndex = 0, counter = 0, objectCount = 0;
		fill_n(normals, 100000, 0);
		fill_n(vertexPositions, 100000, 0);

		cube(SquarePoint1, SquarePoint2, SquarePoint3, SquarePoint4, SquarePoint5, SquarePoint6, SquarePoint7, SquarePoint8);
		objectIndicies[objectCount] = triangleCount;
		objectCount++;
		cube(SmallSquarePoint1, SmallSquarePoint2, SmallSquarePoint3, SmallSquarePoint4, SmallSquarePoint5, SmallSquarePoint6, SmallSquarePoint7, SmallSquarePoint8);
		objectIndicies[objectCount] = triangleCount;
		objectCount++;
		tetra(Point1, Point2, Point3, Point4);
		objectIndicies[objectCount] = triangleCount;
		objectCount++;
		tetra(Point7, Point8, Point5, Point6);
		objectIndicies[objectCount] = triangleCount;
		objectCount++;
		cube(RectanglePoint1, RectanglePoint2, RectanglePoint3, RectanglePoint4, RectanglePoint5, RectanglePoint6, RectanglePoint7, RectanglePoint8);
		objectIndicies[objectCount] = triangleCount;
		objectCount++;


		glBindBuffer(GL_ARRAY_BUFFER, vertexBuffer);
		glBufferData(GL_ARRAY_BUFFER, sizeof(vertexPositions), vertexPositions, GL_STATIC_DRAW);

		glBindBuffer(GL_ARRAY_BUFFER, normalBuffer);
		glBufferData(GL_ARRAY_BUFFER, sizeof(normals), normals, GL_STATIC_DRAW);

		interestX = 0.0f;
		interestY = 1.0f;
		interestZ = 0.0f;

		cameraLocationX = -1.0f;
		cameraLocationY = 1.0f;
		cameraLocationZ = 4.0f;

		cameraUpX = 0.0;
		cameraUpY = 1.0f;
		cameraUpZ = 0.0;

		angleRotate = 0;
	}
	if (key == GLFW_KEY_5 && action == GLFW_PRESS)
	{
		interestX = 0.0f;
		interestY = 0.5f;
		interestZ = 0.0f;

		cameraLocationX = 0.0f;
		cameraLocationY = 0.0f;
		cameraLocationZ = 5.0f;

		cameraUpX = 0.0;
		cameraUpY = 1.0f;
		cameraUpZ = 0.0;

		angleRotate = 0;
	}
	if (key == GLFW_KEY_6 && action == GLFW_PRESS)
	{
		shaderChoice = "orange", currentfractal = "none";
		triangleCount = 0, index = 0, normIndex = 0, objectCount = 0;
		fill_n(normals, 100000, 0);
		fill_n(vertexPositions, 100000, 0);

		curvedTetra(Point9, Point10, Point11, 5);
		curvedTetra(Point9, Point12, Point10, 5);
		curvedTetra(Point9, Point11, Point12, 5);
		curvedTetra(Point12, Point10, Point11, 5);

		/*curvedTetra(Point1, Point2, Point3, 5);
		curvedTetra(Point1, Point4, Point2, 5);
		curvedTetra(Point1, Point3, Point4, 5);
		curvedTetra(Point4, Point2, Point3, 5);*/
		objectIndicies[objectCount] = triangleCount;
		objectCount++;
		glBindBuffer(GL_ARRAY_BUFFER, vertexBuffer);
		glBufferData(GL_ARRAY_BUFFER, sizeof(vertexPositions), vertexPositions, GL_STATIC_DRAW);

		glBindBuffer(GL_ARRAY_BUFFER, normalBuffer);
		glBufferData(GL_ARRAY_BUFFER, sizeof(normals), normals, GL_STATIC_DRAW);

		interestX = 0.0f;
		interestY = 0.0f;
		interestZ = 0.0f;

		cameraLocationX = 0.0f;
		cameraLocationY = 0.0f;
		cameraLocationZ = 3.0f;

		cameraUpX = 0.0;
		cameraUpY = 1.0f;
		cameraUpZ = 0.0;

		angleRotate = 0;
	}
	if (key == GLFW_KEY_W && action == GLFW_PRESS)
	{
		wireFlag = !wireFlag;
	}
	if (key == GLFW_KEY_LEFT && action == GLFW_PRESS)
	{
		interestX -= 0.1f;
		cameraLocationX -= 0.1f;
	}
	if (key == GLFW_KEY_RIGHT && action == GLFW_PRESS)
	{
		interestX += 0.1f;
		cameraLocationX += 0.1f;
	}
	if (key == GLFW_KEY_UP && action == GLFW_PRESS)
	{
		interestY += 0.1f;
		cameraLocationY += 0.1f;
	}
	if (key == GLFW_KEY_DOWN && action == GLFW_PRESS)
	{
		interestY -= 0.1f;
		cameraLocationY -= 0.1f;
	}
	if ((key == GLFW_KEY_MINUS || key == GLFW_KEY_KP_SUBTRACT) && action == GLFW_PRESS)
	{
		interestZ += 0.1f;
		cameraLocationZ += 0.1f;
	}
	if ((key == GLFW_KEY_EQUAL || key == GLFW_KEY_KP_ADD) && action == GLFW_PRESS)
	{
		interestZ -= 0.1f;
		cameraLocationZ -= 0.1f;
	}
	if (key == GLFW_KEY_R && action == GLFW_PRESS)
	{
		lightColor = vec3(1.0f, 0.0f, 0.0f);
	}
	if (key == GLFW_KEY_G && action == GLFW_PRESS)
	{
		lightColor = vec3(0.0f, 1.0f, 0.0f);
	}
	if (key == GLFW_KEY_B && action == GLFW_PRESS)
	{
		lightColor = vec3(0.0f, 0.0f, 1.0f);
	}
	if (key == GLFW_KEY_L && action == GLFW_PRESS)
	{
		lightColor = vec3(1.0f, 1.0f, 1.0f);
	}
	if (key == GLFW_KEY_X && action == GLFW_PRESS)
	{
		xRotateFlag = !xRotateFlag;
		yRotateFlag = false;
		zRotateFlag = false;
		rotateVec = vec3(1.0f, 0.0f, 0.0f);
	}
	if (key == GLFW_KEY_Y && action == GLFW_PRESS)
	{
		yRotateFlag = !yRotateFlag;
		xRotateFlag = false;
		zRotateFlag = false;
		rotateVec = vec3(0.0f, 1.0f, 0.0);
	}
	if (key == GLFW_KEY_Z && action == GLFW_PRESS)
	{
		zRotateFlag = !zRotateFlag;
		xRotateFlag = false;
		yRotateFlag = false;
		rotateVec = vec3(0.0f, 0.0f, 1.0f);
	}
	if (key == GLFW_KEY_S && action == GLFW_PRESS)
	{
		specularFlag = !specularFlag;
	}
	if (key == GLFW_KEY_A && action == GLFW_PRESS)
	{
		ambientFlag = !ambientFlag;
	}
	if (key == GLFW_KEY_D && action == GLFW_PRESS)
	{
		diffuseFlag = !diffuseFlag;
	}
	if (key == GLFW_KEY_P && action == GLFW_PRESS)
	{
		phongFlag = !phongFlag;
		if (phongFlag)
		{
			fprintf(stderr, "You are using Phong shader\n");
		}
		else
		{
			fprintf(stderr, "You are using Gouraud shader\n");
		}
	}
	if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
	{
		exit(0);
	}

	if (key == GLFW_KEY_I && action == GLFW_PRESS)
	{

		if (currentfractal == "triangle")
		{
			counter++, shaderChoice = "orange", index = 0, normIndex = 0, triangleCount = 0, objectCount = 0;
			fill_n(normals, 100000, 0);
			fill_n(vertexPositions, 100000, 0);
			if (counter > 5) counter = 0;
			triangleFractal(Point1, Point2, Point3, Point4, counter);
			objectIndicies[objectCount] = triangleCount;
			objectCount++;
			glBindBuffer(GL_ARRAY_BUFFER, vertexBuffer);
			glBufferData(GL_ARRAY_BUFFER, sizeof(vertexPositions), vertexPositions, GL_STATIC_DRAW);
			glBindBuffer(GL_ARRAY_BUFFER, normalBuffer);
			glBufferData(GL_ARRAY_BUFFER, sizeof(normals), normals, GL_STATIC_DRAW);
		}
		else if (currentfractal == "sponge")
		{
			counter++, shaderChoice = "orange", index = 0, normIndex = 0, triangleCount = 0, objectCount = 0;
			fill_n(normals, 100000, 0);
			fill_n(vertexPositions, 100000, 0);
			if (counter > 2) counter = 0;
			fill_n(normals, 100000, 0);
			fill_n(vertexPositions, 100000, 0);
			Sponge(SpongeSquarePoint1, SpongeSquarePoint2, SpongeSquarePoint3, SpongeSquarePoint4, SpongeSquarePoint5, SpongeSquarePoint6, SpongeSquarePoint7, SpongeSquarePoint8, counter);
			objectIndicies[objectCount] = triangleCount;
			objectCount++;
			glBindBuffer(GL_ARRAY_BUFFER, vertexBuffer);
			glBufferData(GL_ARRAY_BUFFER, sizeof(vertexPositions), vertexPositions, GL_STATIC_DRAW);
			glBindBuffer(GL_ARRAY_BUFFER, normalBuffer);
			glBufferData(GL_ARRAY_BUFFER, sizeof(normals), normals, GL_STATIC_DRAW);
		}
	}
}



GLuint initShader(const char* source, GLenum type)
{
	GLuint shader = glCreateShader(type);
	glShaderSource(shader, 1, (const GLchar**)&source, NULL);
	glCompileShader(shader);

	GLint  compiled;
	glGetShaderiv(shader, GL_COMPILE_STATUS, &compiled);
	if (!compiled) {
		fprintf(stderr, "Failed to compile shader!\n");
		fprintf(stderr, "%s\n", source);

		GLint maxLength = 0;
		glGetShaderiv(shader, GL_INFO_LOG_LENGTH, &maxLength);

		char* infoLog = new char[maxLength];
		glGetShaderInfoLog(shader, maxLength, NULL, infoLog);

		std::cout << infoLog << std::endl;
		free(infoLog);
		exit(EXIT_FAILURE);
	}
	return shader;
}

GLuint initShaders(const char* vertShaderSrc, const char* fragShaderSrc) {
	GLuint program = glCreateProgram();
	glAttachShader(program, initShader(vertShaderSrc, GL_VERTEX_SHADER));
	glAttachShader(program, initShader(fragShaderSrc, GL_FRAGMENT_SHADER));
	glLinkProgram(program);

	/* link  and error check */
	GLint  linked;
	glGetProgramiv(program, GL_LINK_STATUS, &linked);
	if (!linked) {
		std::cerr << "Shader failed to link!\n";
		GLint  logSize = 0;
		glGetProgramiv(program, GL_INFO_LOG_LENGTH, &logSize);

		char* infoLog = new char[logSize];
		glGetProgramInfoLog(program, logSize, NULL, infoLog);
		std::cout << infoLog << std::endl;
		free(infoLog);
		exit(EXIT_FAILURE);
	}
	else {
		// std::cout << "Shaders link successful!\n";
	}
	return program;
}



void initialize() {
	const char* vertexShaderSource =
		"#version 400\n"
		"layout (location = 0) in vec3 vPosition;"
		"layout (location = 1) in vec3 vColor; "
		"layout (location = 2) in vec3 aNormal;"
		"uniform mat4 view;"
		"uniform mat4 objectWorld;"
		"uniform mat4 projection;"
		"uniform vec3 type;"
		"out vec3 color; "
		"out vec3 Normal;"
		"out vec3 FragPos;"
		"void main () {"
		"  FragPos = vec3(objectWorld * vec4(vPosition, 1.0));"
		"  gl_Position = projection * view * (objectWorld  * vec4 (vPosition , 1.0 ));"
		"  if( type == vec3(1.0) )"
		"  {	"
		"     color = vColor; "
		"  }"
		"  else "
		"  {	"
		"     color = vec3(1.0,0.6,0.5); "
		"  }"
		"  Normal = mat3(transpose(inverse(objectWorld))) * aNormal;"
		"}";

	const char* fragmentShaderSource =
		"#version 400\n"
		"in vec3 color;"
		"in vec3 Normal;"
		"in vec3 FragPos;"
		"uniform vec3 ambientMaterial;"
		"uniform vec3 diffuseMaterial;"
		"uniform vec3 specularMaterial;"
		"uniform float shininessMaterial;"
		"uniform vec3 viewPos;"
		"uniform vec3 lightPos;"
		"uniform vec3 lightColor;"
		"uniform vec3 lightProp;"
		"out vec4 frag_color;"
		"void main () {"
		"vec3 norm = normalize(Normal);"
		// ambient
		"vec3 ambient = lightColor * ambientMaterial;"
		// diffuse
		"vec3 lightDir = normalize(lightPos - FragPos);"
		"float diff = max(dot(norm, lightDir), 0.0);"
		"vec3 diffuse = (diff * diffuseMaterial) * lightColor ;"
		// specular
		"vec3 viewDir = normalize(viewPos - FragPos);"
		"vec3 reflectDir = reflect(-lightDir, norm);"
		"float spec = pow(max(dot(viewDir, reflectDir), 0.0), shininessMaterial);"
		"vec3 specular = specularMaterial * spec * lightColor;  "
		// phong
		"vec3 result = ( (ambient * lightProp[0]) + (diffuse * lightProp[1]) + (specular * lightProp[2])) * color;"
		"frag_color = vec4(result, 1.0);"
		"}";

	const char* vertexGourShaderSource =
		"#version 400\n"
		"uniform vec3 ambientMaterial;"
		"uniform vec3 diffuseMaterial;"
		"uniform vec3 specularMaterial;"
		"uniform float shininessMaterial;"
		"layout (location = 0) in vec3 vPosition;"
		"layout (location = 1) in vec3 vColor; "
		"layout (location = 2) in vec3 aNormal;"
		"uniform mat4 view;"
		"uniform mat4 objectWorld;"
		"uniform mat4 projection;"
		"uniform vec3 type;"
		"uniform vec3 viewPos;"
		"uniform vec3 lightPos;"
		"uniform vec3 lightColor;"
		"uniform vec3 lightProp;"
		"out vec3 fragcolor; "
		"void main () {"
		"  vec3 FragPos = vec3(objectWorld * vec4(vPosition, 1.0));"
		"  vec3 color;"
		"  gl_Position = projection * view * (objectWorld  * vec4 (vPosition , 1.0 ));"
		"  if( type == vec3(1.0) )"
		"  {	"
		"     color = vColor; "
		"  }"
		"  else "
		"  {	"
		"     color = vec3(1.0,0.6,0.5); "
		"  }"
		"vec3 norm = normalize(mat3(transpose(inverse(objectWorld))) * aNormal);"
		// ambient
		"vec3 ambient = lightColor * ambientMaterial;"
		// diffuse
		"vec3 lightDir = normalize(lightPos - FragPos);"
		"float diff = max(dot(norm, lightDir), 0.0);"
		"vec3 diffuse = lightColor * (diff * diffuseMaterial);"
		// specular
		"vec3 viewDir = normalize(viewPos - FragPos);"
		"vec3 reflectDir = reflect(-lightDir, norm);"
		"float spec = pow(max(dot(viewDir, reflectDir), 0.0), shininessMaterial);"
		"vec3 specular = lightColor * (spec * specularMaterial);  "
		// phong
		"vec3 result = ( (ambient * lightProp[0]) + (diffuse * lightProp[1]) + (specular * lightProp[2])) * color;"
		"fragcolor = result;"
		"}";

	const char* fragmentGourShaderSource =
		"#version 400\n"
		"in vec3 fragcolor;"
		"out vec4 frag_color;"
		"void main () {"
		"frag_color = vec4(fragcolor, 1.0);"
		"}";

	shaderGourProgram = initShaders(vertexGourShaderSource, fragmentGourShaderSource);
	shaderProgram = initShaders(vertexShaderSource, fragmentShaderSource);

	GLint vPosition = glGetAttribLocation(shaderProgram, "vPosition");
	if (vPosition < 0) std::cerr << "couldn't find vPosition in shader\n";

	GLint aNormal = glGetAttribLocation(shaderProgram, "aNormal");
	if (aNormal < 0) std::cerr << "couldn't find aNormal in shader\n";

	GLint vColor = glGetAttribLocation(shaderProgram, "vColor");
	if (vColor < 0) std::cerr << "couldn't find vColor in shader\n";

	objectWorldUniformLocation = glGetUniformLocation(shaderProgram, "objectWorld");
	if (objectWorldUniformLocation < 0) std::cerr << "couldn't find objectWorld in shader\n";

	lightPosUniformLocation = glGetUniformLocation(shaderProgram, "lightPos");
	if (lightPosUniformLocation < 0) std::cerr << "couldn't find lightPos in shader\n";

	lightColorUniformLocation = glGetUniformLocation(shaderProgram, "lightColor");
	if (lightColorUniformLocation < 0) std::cerr << "couldn't find lightColor in shader\n";

	viewUniformLocation = glGetUniformLocation(shaderProgram, "view");
	if (viewUniformLocation < 0) std::cerr << "couldn't find view in shader\n";

	projectionUniformLocation = glGetUniformLocation(shaderProgram, "projection");
	if (projectionUniformLocation < 0) std::cerr << "couldn't find projection in shader\n";

	typeUniformLocation = glGetUniformLocation(shaderProgram, "type");
	if (typeUniformLocation < 0) std::cerr << "couldn't find type in shader\n";

	lightPropUniformLocation = glGetUniformLocation(shaderProgram, "lightProp");
	if (lightPropUniformLocation < 0) std::cerr << "couldn't find lightProp in shader\n";

	viewPosUniformLocation = glGetUniformLocation(shaderProgram, "viewPos");
	if (viewPosUniformLocation < 0) std::cerr << "couldn't find viewPos in shader\n";

	ambientMaterialUniform = glGetUniformLocation(shaderProgram, "ambientMaterial");
	if (ambientMaterialUniform < 0) std::cerr << "couldn't find ambientMaterial in shader\n";

	diffuseMaterialUniform = glGetUniformLocation(shaderProgram, "diffuseMaterial");
	if (diffuseMaterialUniform < 0) std::cerr << "couldn't find diffuseMaterial in shader\n";

	specularMaterialUniform = glGetUniformLocation(shaderProgram, "specularMaterial");
	if (specularMaterialUniform < 0) std::cerr << "couldn't find specularMaterial in shader\n";

	shininessMaterialUniform = glGetUniformLocation(shaderProgram, "shininessMaterial");
	if (shininessMaterialUniform < 0) std::cerr << "couldn't find shininessMaterial in shader\n";

	glGenBuffers(1, &vertexBuffer);
	glBindBuffer(GL_ARRAY_BUFFER, vertexBuffer);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertexPositions), vertexPositions, GL_STATIC_DRAW);

	glGenBuffers(1, &normalBuffer);
	glBindBuffer(GL_ARRAY_BUFFER, normalBuffer);
	glBufferData(GL_ARRAY_BUFFER, sizeof(normals), normals, GL_STATIC_DRAW);

	glGenBuffers(1, &colorBuffer);
	glBindBuffer(GL_ARRAY_BUFFER, colorBuffer);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertexColors), vertexColors, GL_STATIC_DRAW);

	glGenVertexArrays(1, &VAO);

	glEnable(GL_DEPTH_TEST);
	glClearColor(0.3, 0.3, 0.3, 0.3);
	glDepthFunc(GL_LESS); // depth-testing interprets a smaller value as "closer"
}

void glfwErrorCB(int error, const char* description) {
	fputs(description, stderr);
}

void keyboardCB(GLFWwindow* window, int key, int scancode, int action, int mods) {
	if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
		glfwSetWindowShouldClose(window, GL_TRUE);
}


void renderWorld() {
	vec3 objectAmbient, objectDiffuse, objectSpecular;
	GLfloat objectShininess;
	vec3 type = vec3(0.0);
	vec3 lightProperties = vec3(ambientFlag, diffuseFlag, specularFlag);
	vec3 pointOfInterest = vec3(interestX, interestY, interestZ);
	vec3 cameraLocation = vec3(cameraLocationX, cameraLocationY, cameraLocationZ);
	vec3 cameraUp = vec3(cameraUpX, cameraUpY, cameraUpZ);

	objectAmbient = { 0.1f, 0.1f, 0.1f };
	objectDiffuse = { 1.0f, 0.5f, 0.31f };
	objectSpecular = { 0.6f, 0.6f, 0.6f };
	objectShininess = 16.0f;

	if (shaderChoice == "customColors")
	{
		type = vec3(1.0);
	}
	else
	{
		type = vec3(0.0);
	}

	if (phongFlag)
	{
		glUseProgram(shaderProgram);
	}
	else
	{
		glUseProgram(shaderGourProgram);
	}

	mat4 Xfm = rotate(mat4(1.0f), angleRotate, rotateVec);
	mat4 Projection = perspective(radians(45.0f), 4.0f / 3.0f, 0.1f, 100.0f);         // Use a projection matrix
	mat4 View = lookAt(cameraLocation, pointOfInterest, cameraUp);

	glUniform3fv(ambientMaterialUniform, 1, value_ptr(objectAmbient));
	glUniform3fv(diffuseMaterialUniform, 1, value_ptr(objectDiffuse));
	glUniform3fv(specularMaterialUniform, 1, value_ptr(objectSpecular));
	glUniform1f(shininessMaterialUniform, objectShininess);
	glUniform3fv(viewPosUniformLocation, 1, value_ptr(cameraLocation));
	glUniform3fv(lightPropUniformLocation, 1, value_ptr(lightProperties));
	glUniformMatrix4fv(projectionUniformLocation, 1, GL_FALSE, value_ptr(Projection));
	glUniformMatrix4fv(viewUniformLocation, 1, GL_FALSE, value_ptr(View));
	glUniform3fv(lightColorUniformLocation, 1, value_ptr(lightColor));
	glUniform3fv(lightPosUniformLocation, 1, value_ptr(lightPos));
	glUniform3fv(typeUniformLocation, 1, value_ptr(type));
	glUniformMatrix4fv(objectWorldUniformLocation, 1, GL_FALSE, glm::value_ptr(Xfm));

	// 1st attribute buffer : positions
	glEnableVertexAttribArray(0);
	glBindBuffer(GL_ARRAY_BUFFER, vertexBuffer);
	glVertexAttribPointer(
		0,                  // attribute. No particular reason for 0, but must match the layout in the shader.
		3,                  // size
		GL_FLOAT,           // type
		GL_FALSE,           // normalized?
		0,                  // stride
		(void*)0            // array buffer offset
	);

	glEnableVertexAttribArray(1);
	glBindBuffer(GL_ARRAY_BUFFER, colorBuffer);
	glVertexAttribPointer(
		1,                                // attribute. No particular reason for 1, but must match the layout in the shader.
		3,                                // size
		GL_FLOAT,                         // type
		GL_FALSE,                         // normalized?
		0,                                // stride
		(void*)0                          // array buffer offset
	);

	glEnableVertexAttribArray(2);
	glBindBuffer(GL_ARRAY_BUFFER, normalBuffer);
	glVertexAttribPointer(
		2,                                // attribute. No particular reason for 1, but must match the layout in the shader.
		3,                                // size
		GL_FLOAT,                         // type
		GL_FALSE,                         // normalized?
		0,                                // stride
		(void*)0                          // array buffer offset
	);
	if (wireFlag)
	{
		glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
	}
	else
	{
		glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	}

	if (objectCount > 1)
	{
		glDrawArrays(GL_TRIANGLES, 0, objectIndicies[0] * numVertices);

		objectAmbient = { 0.1f, 0.1f, 0.1f };
		objectDiffuse = { 0.8f, 0.8f, 0.8f };
		objectSpecular = { 0.5f, 0.5f, 0.5f };
		objectShininess = 32.0f;

		glUniform3fv(ambientMaterialUniform, 1, value_ptr(objectAmbient));
		glUniform3fv(diffuseMaterialUniform, 1, value_ptr(objectDiffuse));
		glUniform3fv(specularMaterialUniform, 1, value_ptr(objectSpecular));
		glUniform1f(shininessMaterialUniform, objectShininess);

		glDrawArrays(GL_TRIANGLES, 0, objectIndicies[1] * numVertices);

		objectAmbient = { 0.1f, 0.1f, 0.1f };
		objectDiffuse = { 0.6f, 0.6f, 0.6f };
		objectSpecular = { 1.0f, 0.8f, 1.0f };
		objectShininess = 256.0f;
	}

	

	glUniform3fv(ambientMaterialUniform, 1, value_ptr(objectAmbient));
	glUniform3fv(diffuseMaterialUniform, 1, value_ptr(objectDiffuse));
	glUniform3fv(specularMaterialUniform, 1, value_ptr(objectSpecular));
	glUniform1f(shininessMaterialUniform, objectShininess);

	glDrawArrays(GL_TRIANGLES, 0, triangleCount * numVertices);

	glDisableVertexAttribArray(2);
	glDisableVertexAttribArray(1);
	glDisableVertexAttribArray(0);
}

int main() {
	GLFWwindow* window;
	double currentTime = 0, previousTime = 0;
	glfwSetErrorCallback(glfwErrorCB);
	if (!glfwInit())
		exit(EXIT_FAILURE);

	window = glfwCreateWindow(1080, 880, "COSC 4328 HW 5", NULL, NULL);
	if (!window)
	{
		glfwTerminate();
		return -1;
	}

	/* Make the window's context current */
	glfwMakeContextCurrent(window);
	glewExperimental = GL_TRUE;
	glewInit();  // start GL context and O/S window using the GLFW helper library

	std::cout << "Running OpenGL Version " << glGetString(GL_VERSION)
		<< " using " << glGetString(GL_RENDERER) << "\n\n";

	cout << "Key Commands:\n";
	cout << "1: Scene 1 of Tetra Fractal\n";
	cout << "2: Scene 2 of Close up of gasket\n";
	cout << "3: Scene 3 of Sponge Fractal\n";
	cout << "4: Scene 4 of Scene with various shapes\n";
	cout << "5: Scene 5 of Zoomed out camera\n";
	cout << "6: Sphere\n";
	cout << "A: Ambient light\n";
	cout << "D: Diffuse light\n";
	cout << "S: Specular light\n";
	cout << "L: Normal light (all colors)\n";
	cout << "R: Red light\n";
	cout << "G: Green light\n";
	cout << "B: Blue light\n";
	cout << "X: Rotate on X axis\n";
	cout << "Y: Rotate on Y axis\n";
	cout << "Z: Rotate on Z axis\n";
	cout << "I: iterate on current fractal\n";
	cout << "P: switch between Phong and Gouraud\n";
	cout << "W: Wire representation\n";
	cout << "Use up, down, left, right to navigate current scene\n";
	cout << "+/-: Zoom in/out\n";

	initialize();

	/* Loop until the user closes the window */
	while (!glfwWindowShouldClose(window))
	{
		currentTime = glfwGetTime();
		if ((xRotateFlag || yRotateFlag || zRotateFlag))
		{
			angleRotate += (2*(currentTime - previousTime))/3;
		}
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		glfwSetKeyCallback(window, key_callback);
		renderWorld();
		glfwSwapBuffers(window);
		glfwPollEvents();
		previousTime = currentTime;
	}
}
#pragma once
#include "json.hpp"
#include <string>
#include "directorytree.h"


struct projectUnit{
    std::string projectName;
    std::string airplaneNumber;
    DirectoryTree projectTree;
    std::string readWritePermission;
    std::string applicableTerminals;
    std::string softwareVersion;
    std::string databaseVersion;
};


class ProjectDataManager
{
public:
    ProjectDataManager();
    ~ProjectDataManager();

    static std::vector<projectUnit> projectList;
    static void addProject(json project);
    static void removeProject(std::string projectName);
    static std::vector<projectUnit> getProjectList();
    static projectUnit getProject(std::string projectName);
    static bool isProjectModified(projectUnit project);

    //test
    static void printProjectList();
};


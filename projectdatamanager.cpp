#include "projectdatamanager.h"
#include <QMessageBox>

//静态变量初始化
std::vector<projectUnit> ProjectDataManager::projectList = std::vector<projectUnit>();
size_t ProjectDataManager::projectCurrentIndex = -1;

ProjectDataManager::ProjectDataManager()
{

}

ProjectDataManager::~ProjectDataManager()
{

}

void ProjectDataManager::addProject(json json)
{
    projectUnit newProject;

    if (json.contains("projectName") && json["projectName"].is_string()) {
        newProject.projectName = json["projectName"].get<std::string>();
    }
    else
    {
        QMessageBox::critical(nullptr, "错误", "工程文件配置错误!");
        return;
    }

    if (json.contains("airplaneNumber") && json["airplaneNumber"].is_string()) {
        newProject.airplaneNumber = json["airplaneNumber"].get<std::string>();
    }
    else
    {
        QMessageBox::critical(nullptr, "错误", "工程文件配置错误!");
        return;
    }

    if (json.contains("projectTree")) {
        DirectoryTree newTree;
        newTree.fromJson(json["projectTree"],newTree.getRoot());
        newProject.projectTree = newTree;
    }
    else
    {
        QMessageBox::warning(nullptr, "警告", "空的工程文件!");
    }

    if (json.contains("readWritePermission") && json["readWritePermission"].is_string()) {
        newProject.readWritePermission = json["readWritePermission"].get<std::string>();
    }

    if (json.contains("applicableTerminals") && json["applicableTerminals"].is_string()) {
        newProject.applicableTerminals = json["applicableTerminals"].get<std::string>();
    }

    if (json.contains("softwareVersion") && json["softwareVersion"].is_string()) {
        newProject.softwareVersion = json["softwareVersion"].get<std::string>();
    }

    if (json.contains("databaseVersion") && json["databaseVersion"].is_string()) {
        newProject.databaseVersion = json["databaseVersion"].get<std::string>();
    }

    projectList.push_back(newProject);
}

void ProjectDataManager::removeProject(std::string projectName)
{
    for (std::vector<projectUnit>::iterator it = projectList.begin(); it != projectList.end(); ++it)
    {
        if (it->projectName == projectName)
        {
            projectList.erase(it);
            break;
        }
    }
}

std::vector<projectUnit> ProjectDataManager::getProjectList()
{
    return projectList;
}

#include <stdexcept>

projectUnit ProjectDataManager::getProject(std::string projectName)
{
    for (std::vector<projectUnit>::iterator it = projectList.begin(); it != projectList.end(); ++it)
    {
        if (it->projectName == projectName)
        {
            return *it;
        }
    }
    // 抛出一个异常
    throw std::runtime_error("Project not found: " + projectName);
}

projectUnit ProjectDataManager::getProject(size_t index)
{
    return projectList[index];
}

bool ProjectDataManager::isProjectModified(projectUnit project)
{
    bool isModified = false;
    //查找工程
    std::vector<projectUnit>::iterator it;
    for (it = projectList.begin(); it != projectList.end(); ++it)
    {
        if (it->projectName == project.projectName)
        {
            break;
        }
    }

    //检查是否修改
    if (it->projectName != project.projectName)
    {
        isModified = true;
    }
    else if (it->airplaneNumber != project.airplaneNumber)
    {
        isModified = true;
    }
    else if (it->projectTree.toJson(it->projectTree.getRoot()) != project.projectTree.toJson(project.projectTree.getRoot()))
    {
        isModified = true;
    }
    else if (it->readWritePermission != project.readWritePermission)
    {
        isModified = true;
    }
    else if (it->applicableTerminals != project.applicableTerminals)
    {
        isModified = true;
    }
    else if (it->softwareVersion != project.softwareVersion)
    {
        isModified = true;
    }
    else if (it->databaseVersion != project.databaseVersion)
    {
        isModified = true;
    }
    return isModified;
}

void ProjectDataManager::printProjectList()
{
    std::cout << std::endl << std::endl;
    for (std::vector<projectUnit>::iterator it = projectList.begin(); it != projectList.end(); ++it)
    {
        std::cout << "projectName: " << it->projectName << std::endl;
        std::cout << "airplaneNumber: " << it->airplaneNumber << std::endl;
        std::cout << "projectTree: " << it->projectTree.toJson(it->projectTree.getRoot()).dump(4) << std::endl;
        std::cout << "readWritePermission: " << it->readWritePermission << std::endl;
        std::cout << "applicableTerminals: " << it->applicableTerminals << std::endl;
        std::cout << "softwareVersion: " << it->softwareVersion << std::endl;
        std::cout << "databaseVersion: " << it->databaseVersion << std::endl;
        std::cout<< std::endl;
    }
}



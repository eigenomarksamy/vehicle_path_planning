#pragma once

#include <stdint.h>
#include <fstream>
#include <ostream>
#include <memory>
#include <vector>
#include <string>

class Logger_C
{
public:

    struct Logger_Data_S
    {
        /* data */
    };
    

    enum class Extension_EC { Ext_None, Ext_Txt, Ext_Csv };

protected:
    /**
     * @brief sets the file name member
     */
    void setFileName(std::string fileName) { file_name_ = fileName; }

    /**
     * @brief extracts the extension of the file
     * @return extension
     */
    Extension_EC extractExtension() const;

    /**
     * @brief writes data to text file
     * @returns validity flag
     */
    bool writeDataToTxt();

private:

    /** \brief final file object */
    std::unique_ptr<std::ostream> p_file_to_write_;

    /** \brief final vector of data */
    std::vector<Logger_Data_S> v_logger_data_;

    /** \brief file name */
    std::string file_name_;
};
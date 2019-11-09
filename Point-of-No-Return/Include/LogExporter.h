#include <fstream>
#include <iostream>
#include <limits.h>
#include <string>
#include <time.h>

/**
* @class LogExporter
* @brief Log出力クラス
*/
class LogExporter {
public:

	/**
	* @brief コンストラクタ
	* @param filename ファイル名
	*/
	LogExporter(std::string filename);

	/**
	* @brief デストラクタ
	*/
	~LogExporter();

	/**
	* @brief 書き込み
	* @param string 出力内容
	*/
	void Write(std::string string);

private:

	//! ファイルオブジェクト
	std::ofstream file;

	//! 64bitの時間オブジェクト
	time_t current_time;

	//! 時間を要素別に分けたオブジェクト(年月や日時など)
	tm time_element;

	/**
	* @brief ファイル作成
	* @param filename ファイル名
	*/
	void CreateFile(std::string filename);

	/**
	* @brief ラップされたファイルを閉じる関数
	*/
	void CloseFile();

	/**
	* @brief 時刻を文字へ変換する
	* @return 時刻の文字列
	*/
	std::string TimeToString();
};

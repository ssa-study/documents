//　 クラスデザインテンプレート



namespace ssa {



  class ClassDesign {

  public:
    // 引数のないデフォルトコンストラクタを用意する。
    ClassDesign()
      : m_intMember(0)          // メンバの初期化を必ず行う。=での代入はしない。
      , m_classMember()
      , m_containerMember(30)   // コンテナのサイズ確保をここで行うと効率的
	  , m_hoge(0)
    {}
    // コピーコンストラクタを用意する。
    // 決して=operatorで代用してはいけない
    ClassDesign(const ClassDesign& src)
      : m_intMember(src.m_intMemver)
      , m_classMember(src.m_classMember)
      , m_containerMember(src.m_containerMember)
	  , m_hoge(src.m_hoge.clone())
    {}
    // このクラスが継承される可能性がある場合は、仮想デストラクタを用意する
    virtual ~ClassDesign()
    {
		if (m_hoge != 0) Hoge::Destory(m_hoge);
	}

    // swapの実装。決して例外をthrowしない。
    // 基本的に各メンバをそれぞれswapする
    void swap(ClassDesign& src) {
      swap(m_intMember, src.m_intMember);
      swap(m_classMember, src.m_classMember);
      swap(m_containerMember, src.m_containerMember);
	  swap(m_hoge, src.m_hoge);
    }

    // =オペレータは,コピーとswapで実装する
    ClassDesign& operator = (ClassDesign src) { // 引数srcを実体にすることで、srcのコピーを生成する。
      swap(src); // 自分自身とsrcのコピーを入れ替える
      return *this; // 古い自分自身はここで捨てられる
    }

    // インスタンスの初期化は、デフォルトコンストラクタを使う
    void clear() {
      swap(ClassDesign());
    }

  private:
    int m_intMemver;
    ClassA m_classMember;
    vector<ClassA> m_containerMember;
	Hoge* m_hoge;
  };

  // swapのオーバーライドによってswapを定義する。
  // ネームスペース外からClassDesignのswapを実行した場合でもこのswapが参照される
  inline void swap(ClassDesign& a, ClassDesign& b) {
    a.swap(b);
  }



  vector<ClassDesign> listA;
  vector<ClassDesign*> listB;
  vector<shared_ptr<ClassDesign> > listC;

  // ClassDesignの生成とコピーが軽い場合
  listA > listC > listB
  // ClassDesignの生成とコピーが重い場合
  listC > listA > listB

  listBは極力避けるべき。
  ※vectorなどのコンテナは、クラスオブジェクトの実体か、そのshared_ptr以外のものを入れないほうが良い。（サッター談)



  悪意のあるプログラム
  ClassDesign bad;
  bad.m_name = "       ....セキュリティーホールを突くコード";
  ClassDesign().swap(bad);




} // namespace ssa

template <typename T>
void swap(T& a, T& b) {
	T tmp = a;
	a = b;
	b = tmp;
}

namespace hoge {
	ssa::ClassDesign a;
	ssa::ClassDesign b;
	swap(a,b);
}

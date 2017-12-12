//�@ �N���X�f�U�C���e���v���[�g



namespace ssa {



  class ClassDesign {

  public:
    // �����̂Ȃ��f�t�H���g�R���X�g���N�^��p�ӂ���B
    ClassDesign()
      : m_intMember(0)          // �����o�̏�������K���s���B=�ł̑���͂��Ȃ��B
      , m_classMember()
      , m_containerMember(30)   // �R���e�i�̃T�C�Y�m�ۂ������ōs���ƌ����I
	  , m_hoge(0)
    {}
    // �R�s�[�R���X�g���N�^��p�ӂ���B
    // ������=operator�ő�p���Ă͂����Ȃ�
    ClassDesign(const ClassDesign& src)
      : m_intMember(src.m_intMemver)
      , m_classMember(src.m_classMember)
      , m_containerMember(src.m_containerMember)
	  , m_hoge(src.m_hoge.clone())
    {}
    // ���̃N���X���p�������\��������ꍇ�́A���z�f�X�g���N�^��p�ӂ���
    virtual ~ClassDesign()
    {
		if (m_hoge != 0) Hoge::Destory(m_hoge);
	}

    // swap�̎����B�����ė�O��throw���Ȃ��B
    // ��{�I�Ɋe�����o�����ꂼ��swap����
    void swap(ClassDesign& src) {
      swap(m_intMember, src.m_intMember);
      swap(m_classMember, src.m_classMember);
      swap(m_containerMember, src.m_containerMember);
	  swap(m_hoge, src.m_hoge);
    }

    // =�I�y���[�^��,�R�s�[��swap�Ŏ�������
    ClassDesign& operator = (ClassDesign src) { // ����src�����̂ɂ��邱�ƂŁAsrc�̃R�s�[�𐶐�����B
      swap(src); // �������g��src�̃R�s�[�����ւ���
      return *this; // �Â��������g�͂����Ŏ̂Ă���
    }

    // �C���X�^���X�̏������́A�f�t�H���g�R���X�g���N�^���g��
    void clear() {
      swap(ClassDesign());
    }

  private:
    int m_intMemver;
    ClassA m_classMember;
    vector<ClassA> m_containerMember;
	Hoge* m_hoge;
  };

  // swap�̃I�[�o�[���C�h�ɂ����swap���`����B
  // �l�[���X�y�[�X�O����ClassDesign��swap�����s�����ꍇ�ł�����swap���Q�Ƃ����
  inline void swap(ClassDesign& a, ClassDesign& b) {
    a.swap(b);
  }



  vector<ClassDesign> listA;
  vector<ClassDesign*> listB;
  vector<shared_ptr<ClassDesign> > listC;

  // ClassDesign�̐����ƃR�s�[���y���ꍇ
  listA > listC > listB
  // ClassDesign�̐����ƃR�s�[���d���ꍇ
  listC > listA > listB

  listB�͋ɗ͔�����ׂ��B
  ��vector�Ȃǂ̃R���e�i�́A�N���X�I�u�W�F�N�g�̎��̂��A����shared_ptr�ȊO�̂��̂����Ȃ��ق����ǂ��B�i�T�b�^�[�k)



  ���ӂ̂���v���O����
  ClassDesign bad;
  bad.m_name = "       ....�Z�L�����e�B�[�z�[����˂��R�[�h";
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

pkgname="sstring"
pkgver="15.5.0"
pkgrel="4"
pkgdesc="Memory Safe String Library in C language."
arch=("x86_64" "i686")
conflicts=('sstring')
depends=(gcc)
license=("MIT")
source=("https://raw.githubusercontent.com/Dark-CodeX/SafeString/main/sstring/sstring.h" "https://raw.githubusercontent.com/Dark-CodeX/SafeString/main/sstring/prototype_err.h" "https://raw.githubusercontent.com/Dark-CodeX/SafeString/main/sstring/binary.h")
sha512sums=("20aaf9c95ce8c8338a1abcc4c7379441c38972054e29845ff4c1f4781ce508fd1c766272d22ba0d5e10b5427941acedca542f93a1a3d12d29a801629b3556b00" "7c30fcca1a5fe35d44c238b903a581a70c9647d682fe5f7218623505c72cddd6a86181073bfc83594c94882dad89ab5282e3e381777906de86b9902792b67367" "bf25da32ad102c735cc52089d520e4fffa05af6d05926d239faddb43a1163da584689e1d0f193cb564e7224cd4db89e1ee506692fd97fc0cea483058db0045ef")

package() {
  echo "Memory Safe String Library in C language."
  mkdir -p "${pkgdir}/usr/include/sstring"
  cp "${srcdir}/sstring.h" "${pkgdir}/usr/include/sstring/sstring.h"
  cp "${srcdir}/prototype_err.h" "${pkgdir}/usr/include/sstring/prototype_err.h"
  cp "${srcdir}/binary.h" "${pkgdir}/usr/include/sstring/binary.h"
  echo "Done!"
}

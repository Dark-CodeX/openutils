pkgname="sstring"
pkgver="4.2.7"
pkgrel="3"
pkgdesc="Memory Safe String Library in C language."
arch=("x86_64" "i686")
conflicts=('sstring')
depends=(gcc)
license=("MIT")
source=("https://raw.githubusercontent.com/Dark-CodeX/SafeString/main/sstring/sstring.h" "https://raw.githubusercontent.com/Dark-CodeX/SafeString/main/sstring/prototype_err.h")
sha512sums=("346cf84b5b4327b407d9eb5ede2ec6a911bf050e5e2ed0132036fdf9e91925186da94c7ac08b76448f2010d460cb286fe116886ca437a3833c404ca948e76c93" "bea6b78958bfb6c48c780a80119918758f3c7753a73f5e020b9bfbeaf3eb47cf34ba80cbf277ee28fb589275e1cd1e4d2e3e534f43caf648affbce2b552d59e3")

package() {
  echo "Memory Safe String Library in C language."
  mkdir -p "${pkgdir}/usr/include/sstring"
  cp "${srcdir}/sstring.h" "${pkgdir}/usr/include/sstring/sstring.h"
  cp "${srcdir}/prototype_err.h" "${pkgdir}/usr/include/sstring/prototype_err.h"
  echo "Done!"
}

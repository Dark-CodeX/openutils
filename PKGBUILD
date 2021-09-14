pkgname="sstring"
pkgver="7.1.1"
pkgrel="4"
pkgdesc="Memory Safe String Library in C language."
arch=("x86_64" "i686")
conflicts=('sstring')
depends=(gcc)
license=("MIT")
source=("https://raw.githubusercontent.com/Dark-CodeX/SafeString/main/sstring/sstring.h" "https://raw.githubusercontent.com/Dark-CodeX/SafeString/main/sstring/prototype_err.h" "https://raw.githubusercontent.com/Dark-CodeX/SafeString/main/sstring/binary.h")
sha512sums=("0035c023e512aaff9cef8362ebc978b0bdac28591022c7044f94a69d2976a2e1d78c6e2075c95523cc151e6d40fe4014fdcb4e1efb6b8a56b107e86cf6659718" "4c6c6b945d6111bbedcfa1d539efc4de7759d048eca2e77a18138e88f6eb051ec72b88a39345191b6415a8795ba1fda1f316a6662e19f179ecb7b048050c0423" "4eed793a4ecafcab261e9a1981da29aff3db7cc24a70841c5c852235ed6325ee70177471475170d0fa8bbcff5c71babc64948ba8c001ef035ee6ebcaae159e8d")

package() {
  echo "Memory Safe String Library in C language."
  mkdir -p "${pkgdir}/usr/include/sstring"
  cp "${srcdir}/sstring.h" "${pkgdir}/usr/include/sstring/sstring.h"
  cp "${srcdir}/prototype_err.h" "${pkgdir}/usr/include/sstring/prototype_err.h"
  cp "${srcdir}/binary.h" "${pkgdir}/usr/include/sstring/binary.h"
  echo "Done!"
}

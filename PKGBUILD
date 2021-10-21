pkgname="sstring"
pkgver="30.0.0"
pkgrel="5"
pkgdesc="Memory Safe String Library in C language."
arch=("x86_64" "i686")
conflicts=('sstring')
depends=(gcc)
license=("MIT")
source= ("https://raw.githubusercontent.com/Dark-CodeX/SafeString/main/sstring/sstring.h" "https://raw.githubusercontent.com/Dark-CodeX/SafeString/main/sstring/prototype_err.h" "https://raw.githubusercontent.com/Dark-CodeX/SafeString/main/sstring/binary.h" "https://raw.githubusercontent.com/Dark-CodeX/SafeString/main/sstring/morse_code.h")

sha512sums=("34ecbde7312ffc10aa405c4b47033e02fa6a73344c0152e248cbe2f8b506c1ed2254ec3ad5ef93b52e1f20fbcad4e4634b1186af9696526de1b0ce3decb48938" "6d1364195fdebd10a124295cc6c969af105251817f2c01a559c33862ddc5214b734a673bb2ce8f37209bd1ae916bf67ea54c7cb76d352b3fd162d1d585a0b516" "11053333b0ac1fedc1842a90c1996664e27fb3969d8c219342a9893b5fc11873fa884a42f3c943c7595f4217b404181375758b1993403b375c93fb23787c81d2",  "7e034af1feede35eccc270cd6c4429581597d6854406b991f14a3e98121061aa11f6f6975033f286aadab8a2b7421b8dfebb35e2288e82e0d655a1756273f0d5")

package() {
  echo "Memory Safe String Library in C language."
  mkdir -p "${pkgdir}/usr/include/sstring"
  cp "${srcdir}/sstring.h" "${pkgdir}/usr/include/sstring/sstring.h"
  cp "${srcdir}/prototype_err.h" "${pkgdir}/usr/include/sstring/prototype_err.h"
  cp "${srcdir}/binary.h" "${pkgdir}/usr/include/sstring/binary.h"
  cp "${srcdir}/morse_code.h" "${pkgdir}/usr/include/sstring/morse_code.h"
  echo "Done!"
}

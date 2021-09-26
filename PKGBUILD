pkgname="sstring"
pkgver="11.0.0"
pkgrel="4"
pkgdesc="Memory Safe String Library in C language."
arch=("x86_64" "i686")
conflicts=('sstring')
depends=(gcc)
license=("MIT")
source=("https://raw.githubusercontent.com/Dark-CodeX/SafeString/main/sstring/sstring.h" "https://raw.githubusercontent.com/Dark-CodeX/SafeString/main/sstring/prototype_err.h" "https://raw.githubusercontent.com/Dark-CodeX/SafeString/main/sstring/binary.h")
sha512sums=("22923f022daf32a085a4c18dd4a08c6a8b1241bac190fbf7c83ce530fbe867a966576d6f6c5388d67f37a4bdd223d593b563e9627ea3569b324c50e015c3d7b5" "c2998237e5ac9f30a65a6313e8a16fa34b3198ab84ee850dba6783945a99f9d65656b036fbbf950d7767dc0318298a1ea577660c58ae67c61023dd64545d2552" "aac5a3002068b2488e42e63c5db482e22d2e9c1068852a30a2c296b91c2de8f0dcc1d4b151c06290c2c172d5953f60c55986cdd69e15bf7162ec5903c58d38e0")

package() {
  echo "Memory Safe String Library in C language."
  mkdir -p "${pkgdir}/usr/include/sstring"
  cp "${srcdir}/sstring.h" "${pkgdir}/usr/include/sstring/sstring.h"
  cp "${srcdir}/prototype_err.h" "${pkgdir}/usr/include/sstring/prototype_err.h"
  cp "${srcdir}/binary.h" "${pkgdir}/usr/include/sstring/binary.h"
  echo "Done!"
}

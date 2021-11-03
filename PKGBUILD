pkgname="sstring"
pkgver="40.0.0"
pkgrel="5"
pkgdesc="Memory Safe String Library in C language."
arch=("x86_64" "i686")
conflicts=('sstring')
depends=(gcc)
license=("MIT")
source=(
  "https://raw.githubusercontent.com/Dark-CodeX/SafeString/main/sstring/sstring.h"
  "https://raw.githubusercontent.com/Dark-CodeX/SafeString/main/sstring/prototype_err.h"
  "https://raw.githubusercontent.com/Dark-CodeX/SafeString/main/sstring/binary.h"
  "https://raw.githubusercontent.com/Dark-CodeX/SafeString/main/sstring/morse_code.h")

sha512sums=(
  "ab490d745eaf96f7e229f65545ed73cd2ee410877750962a0003e5e899acd5943c12920066253af597f6c525af1122c083a2dd003bd2b772b21a51df1a93f1d6"
  "8bf5487e60ec8135af490762124c654a7ff39ef4dedd91f9c2dc82e78890455e383b236bc6472f3934ba1baf5a57572186655c6ca5e9f544ffddac3203c0d1f8"
  "9c7fdae851342e23cd80c4fc9ca67871b7952f382dbade2f60ffb6b293ef728d7dae6ce8b3f1e0184a933808a4d10c46e6cad62daccecf51c07d5638f2b20433"
  "94b332a65c4d060dd2ca9d143e1fab901a9db3d7658b32a16ac7a8e412c4005403cf5891a2cb4d594fde814b88bb7749e540b11358778637225330249729ccf6")

package() {
  echo "Memory Safe String Library in C language."
  mkdir -p "${pkgdir}/usr/include/sstring"
  cp "${srcdir}/sstring.h" "${pkgdir}/usr/include/sstring/sstring.h"
  cp "${srcdir}/prototype_err.h" "${pkgdir}/usr/include/sstring/prototype_err.h"
  cp "${srcdir}/binary.h" "${pkgdir}/usr/include/sstring/binary.h"
  cp "${srcdir}/morse_code.h" "${pkgdir}/usr/include/sstring/morse_code.h"
  echo "Done!"
}
